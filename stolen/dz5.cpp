#include <iostream>

using namespace std;

class arra
{
private:
    int m [255];
    int n;

public:
arra ();
arra (int l);
arra operator +(const arra &X);
};

arra::arra ()
{
puts ("help");
}

arra::arra (int l)
{
    n=l;
    int i;
    for (i=0;i<n;i++)
    {cin >> m[i];}
    puts ("help");
}

arra arra::operator +(const arra &x)
{
    int l,r;
    if(n>x.n)
    { l=n;
      r=x.n;
    } else {l=x.n; r=n;}
    arra Y;
    Y.n=l;
    for (int i=0;i<r;i++)
    {
        Y.m[i]=m[i]+x.m[i];

    }
    for (int i=0;i<r;i++)
     cout << Y.m[i];
return Y;
}


int main()
{arra A(4);
arra B(5);
arra C(11);
C=A+B;
return 0;
}
