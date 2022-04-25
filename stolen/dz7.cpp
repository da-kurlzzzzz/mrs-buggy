#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
};
class surname;

class frame {
protected:
    char c;
    int Ax, Ay, Bx, By;

public:
    frame(char h, int Cx, int Cy, int Dx, int Dy)
    {
        c = h;
        Ax = Cx;
        Ay = Cy;
        Bx = Dx;
        By = Dy;
    };
    void output()
    {
        for (int i = 0; i < (Bx - Ax); i++) {
            gotoXY(Ax + i, Ay);
            putchar(c);
        };
        for (int i = 0; i < (By - Ay); i++) {
            gotoXY(Bx, Ay + i);
            putchar(c);
        };
        for (int i = 0; i < (Bx - Ax); i++) {
            gotoXY(Bx - i, By);
            putchar(c);
        };
        for (int i = 0; i < (By - Ay); i++) {
            gotoXY(Ax, By - i);
            putchar(c);
        };
    };
};

class surname {
protected:
    char s[100];
    int x, y, l;

public:
    surname();

    void input(int, int);
    void output();
};

class surname_in_frame : public surname, public frame

{
public:
    surname_in_frame(char h, int Cx, int Cy, int Dx, int Dy)
        : surname()
        , frame(h, Cx, Cy, Dx, Dy)
    {
        puts("hey");
    };
    void output(int, int);
};
void surname::input(int ax, int ay)
{
    x = ax;
    y = ay;
    cout << "surname= " << endl;
    cin >> s;
    l = strlen(s);
};

void surname::output()
{
    gotoXY(x, y);
    cout << s;
};

int main()
{
    int Cx, Cy, Dx, Dy;
    int ax, ay;
    surname_in_frame sur_f('&', Cx, Cy, Dx, Dy);
    cout << "x=";
    cin >> ax;
    cout << "y=";
    cin >> ay;
    sur_f.output(ax, ay);

    return 0;
};

surname::surname()
{
    int l = strlen(s);
    for (int i = 0; i < l; i++)
        s[i] = 0;
};

void surname_in_frame ::output(int ax, int ay)
{
    surname::input(ax, ay);
    surname::output();
    Ax = x - 5;
    Ay = y - 5;
    Bx = Ax + l + 10;
    By = y + 5;
    frame::output();
};
