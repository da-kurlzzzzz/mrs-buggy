#include <SDL2/SDL.h>

class TStar {
private:
    SDL_Point position;
    SDL_Point velocity;
    int size;
    SDL_bool hit;

public:
    TStar();
    TStar(SDL_Point pos, SDL_Point vel);
    void Draw(SDL_Renderer* rend);
    void Step();
    int getSize();
    void setPos(SDL_Point pos);
    SDL_Point getPos();
    void setVel(SDL_Point vel);
    SDL_bool wasHit();
    void markAsHit();
};

TStar::TStar() {
    this->position = {0, 0};
    this->velocity = {0, 0};
    this->size = 8;
    this->hit = SDL_FALSE;
}

TStar::TStar(SDL_Point pos, SDL_Point vel) {
    this->position = pos;
    this->velocity = vel;
    this->size = 8;
    this->hit = SDL_FALSE;
}

void TStar::Draw(SDL_Renderer* rend) {
    SDL_Rect repr = { this->position.x - this->size/2,
                      this->position.y - this->size/2,
                      this->size,
                      this->size };
    SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(rend, &repr);
}

void TStar::Step() {
    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;
}

int TStar::getSize() {
    return this->size;
}

void TStar::setPos(SDL_Point pos) {
    this->position = pos;
}

SDL_Point TStar::getPos() {
    return this->position;
}

void TStar::setVel(SDL_Point vel) {
    this->velocity = vel;
}

SDL_bool TStar::wasHit() {
    return this->hit;
}

void TStar::markAsHit() {
    this->hit = SDL_TRUE;
}

class TFrame {
protected:
    TStar stars[76]; // frame 20 x 20

public:
    TFrame() {}
    TFrame(SDL_Point pos);
    void Draw(SDL_Renderer* rend);
    SDL_Rect getRect();
};

TFrame::TFrame(SDL_Point center) {
    int index = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (i == 0 || i == 19 || j == 0 || j == 19) {
                SDL_Point pos = center;
                pos.x += (2 * i - 19) * this->stars[index].getSize();
                pos.y += (2 * j - 19) * this->stars[index].getSize();
                this->stars[index].setPos(pos);
                index++;
            }
        }
    }
}

void TFrame::Draw(SDL_Renderer* rend) {
    for (unsigned i = 0; i < sizeof(this->stars) / sizeof(this->stars[0]); ++i) {
        this->stars[i].Draw(rend);
    }
}

SDL_Rect TFrame::getRect() {
    SDL_Point corner = this->stars[0].getPos();
    for (int i = 1; i < 76; ++i) {
        SDL_Point tmp = this->stars[i].getPos();
        if (tmp.x < corner.x || tmp.y < corner.y) {
            corner = tmp;
        }
    }
    int size = this->stars[0].getSize();
    return {corner.x, corner.y, 39 * size, 39 * size};
}

class TMovingFrame : public TFrame {
protected:
    SDL_Point velocity;

public:
    TMovingFrame(SDL_Point center, SDL_Point velocity);
    void Step();
};

void TMovingFrame::Step() {
    for (int i = 0; i < 76; ++i) {
        this->stars[i].Step();
    }
}

TMovingFrame::TMovingFrame(SDL_Point center, SDL_Point velocity) {
    int index = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (i == 0 || i == 19 || j == 0 || j == 19) {
                SDL_Point pos = center;
                pos.x += (2 * i - 19) * this->stars[index].getSize();
                pos.y += (2 * j - 19) * this->stars[index].getSize();
                this->stars[index].setPos(pos);
                this->stars[index].setVel(velocity);
                index++;
            }
        }
    }
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    TMovingFrame tester({320, 240}, {-1, 1});
    TStar bullet({320, 240}, {1, 1});
    int points_hit = 0;

    SDL_Window* screen;
    SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer(640, 480, 0, &screen, &renderer);

    SDL_Event event;
    SDL_bool done = SDL_FALSE;
    while(!done) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
            case SDL_QUIT:
                done = SDL_TRUE;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    done = SDL_TRUE;
                }
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        tester.Draw(renderer);
        tester.Step();
        bullet.Draw(renderer);
        bullet.Step();
        SDL_Point tmp_pos = bullet.getPos();
        SDL_Rect tmp_box = tester.getRect();
        if (!bullet.wasHit() && SDL_PointInRect(&tmp_pos, &tmp_box)) {
            points_hit++;
            bullet.markAsHit();
            SDL_Log("Hit a point\n");
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(50);
    }

    SDL_Quit();

    return 0;
}
