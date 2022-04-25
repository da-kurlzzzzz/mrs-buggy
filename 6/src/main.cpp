#include <SDL2/SDL.h>

int main(int argc, char** argv) {
    SDL_Log("Ignoring arguments:\n");
    for(int i = 0; i < argc; ++i) {
        SDL_Log("%s\n", argv[i]);
    }

    if(0 != SDL_Init(SDL_INIT_VIDEO)) {
        printf("Unable to init SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* screen;
    SDL_Renderer* renderer;
    if(SDL_CreateWindowAndRenderer(640, 480, 0, &screen, &renderer)) {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

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
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    SDL_Log("Exited cleanly\n");

    return 0;
}
