#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x,int y)
{CursorPosition.X=x;
CursorPosition.Y=y;
SetConsoleCursorPosition (console,CursorPosition);
};

class star;
class rectangle
{
    private:
        int Ax, Ay, Bx, By;
    public:
        char c;
        rectangle (char, int, int, int, int);
        void show();

};
class Mrectangle : public rectangle
{
private:
    int MAx,MAy,MBx,MBy;
public:
    Mrectangle(char c,int Ax, int Ay, int Bx, int By,int l):rectangle(c,Ax,Ay,Bx,By)
    {
        MAx=Ax+l;
        MAy=Ay+l;
        MBx=Bx+l;
        MBy=By+l;
    }
    void print();
};

class star
{int x,y,l; char ch;
public: star (int i, int j,int l);
void prn ();
int output_x() { return x; };
int output_y() { return y; };
int output_l(){return l;};
void operator ++()
{x+=l;}
void operator ++(int)
{
    y+=l;
}
void operator -- ()
{
    x-=l;
}
void operator -- (int)
{
    y-=l;
}
};

star::star(int myx, int my,int myl)
{   ch = '*';
    x = myx;
    y = my;
    l=myl;
}
rectangle::rectangle(char z, int Cx, int Cy, int Dx, int Dy)
{
    c = z;
    Ax = Cx;
    Ay = Cy;
    Bx = Dx;
    By = Dy;
};

void star::prn()
{
    gotoXY(x,y);
    cout << ch;
};
void rectangle::show()
{
    for (int i = 0; i < (Bx - Ax); i++)
    {
        gotoXY(Ax + i, Ay);
        putchar ( c );
    };
    for (int i = 0; i < (By - Ay); i++)
    {
        gotoXY(Bx, Ay + i);
        putchar(c);
    };
    for (int i = 0; i < (Bx - Ax); i++)
    {
        gotoXY(Bx - i, By);
        putchar(c);
    };
    for (int i = 0; i < (By - Ay); i++)
    {
        gotoXY(Ax, By - i);
        putchar(c);
    };
};
void Mrectangle::print()
{
    for (int i = 0; i < (MBx - MAx); i++)
    {
        gotoXY(MAx + i, MAy);
        putchar ( c );
    };
    for (int i = 0; i < (MBy - MAy); i++)
    {
        gotoXY(MBx, MAy + i);
        putchar(c);
    };
    for (int i = 0; i < (MBx - MAx); i++)
    {
        gotoXY(MBx - i, MBy);
        putchar(c);
    };
    for (int i = 0; i < (MBy - MAy); i++)
    {
        gotoXY(MAx, MBy - i);
        putchar(c);
    };
};

main()
{
int a,b,c,d,i,j,l,k;
cout<<"x1=";
cin>>a;
cout<<"y1=";
cin>>b;
cout<<"x2=";
cin>>c;
cout<<"y2=";
cin>>d;
cout<<"x=";
cin>>i;
cout<<"y=";
cin>>j;
cout<<"length of fly=";
cin>>l;
cout<<"move rectangle=";
cin>>k;
rectangle R ('/',a,b,c,d);
Mrectangle MR('/',a,b,c,d,k);
R.show();
MR.print();
star Z(i,j,l);
Z.prn();
Z++;
Z.prn();
}
