#include <iostream>

using namespace std;

class matrix;
class array
{
private:
    int m [255];
    int n;

public:

array (int l);
int &index (int i)
    {
    return m[i];
    }

friend int intersec (array,matrix);
};

class matrix
{
    int x [255][255];
    int s;
    int r;

public:
    matrix (int k, int l);
    int &index(int i,int j)
    {
        return x[i][j];
    }
void input (int s,int r);
    friend int intersec (array, matrix);
};

array::array (int l)
{
    n=l;
    int i;
    for (i=0;i<n;i++)
    {cin >> m[i];}
}

matrix::matrix (int k, int l)
{
    s=k;
    r=l;
    int i,j;
for (i=0;i<s;i++)
{
    for (j=0;j<r;j++)
    {
        cin >> x[i][j];
    }
}
}

int intersec (array z, matrix y)
{
    int i,j,k;
    int l;
    for (i=0;i<y.s;i++)
    {
        for (j=0;j<y.r;j++)
        {
            for(k=0;k<z.n;k++)
            {
                if (z.m[k]==y.x[i][j])
                    l=i+1;

                //cout << i+1;
                //else continue;
            }
        } if(l!=i) cout << l;

    }
}

void matrix::input(int s,int r)
{ int i,j;
for (i=0;i<s;i++)
{
    for (j=0;j<r;j++)
    {
        cout << x[i][j];
    }
}
}
int main()
{array A(4);
matrix M (3,2);
M.input(3,2);
//int f;
intersec (A,M);
return 0;
}
