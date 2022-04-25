#include <iostream>

using namespace std;

class array
{
private:
    int m [255];

public:
    int n;
    int max1=-37000;
int i;
    array(int l);

   /* int &index (int i)
    {
    return m[i];
    }*/
int maxi()
    {for (i=0;i<n;i++)
{


        if (m[i]> max1)
        {
            max1 = m[i];
        }

}return max1;}
};

array::array(int l)
{
    n=l;
    int i;
    for (i=0;i<n;i++)
    {cin >> m[i];}
}

/*array::index(int i)
{
    return m[i];
}*/


int main()
{array A(1);
array B(2);
array C(3);
int supermax=A.maxi()+B.maxi()+C.maxi();


/*int max1=-36000;
int max2=-38000;
int max3=-39000;
int i;
int n=3;

/*for (i=0;i<n;i++)
{


        if (A.index(i) > max1)
        {
            max1 = A.index(i);
        }
        if (B.index(i) > max2)
        {
            max2 = B.index(i);
        }
        if (C.index(i) > max3)
        {
            max3 = C.index(i);
        }

}*/
//supermax=max1+max2+max3;
cout << supermax;
return 0;
}


