#include <iostream>

using namespace std;

class MN
{
private:
    int m [255];
    int n;

public:
MN (int l);

int &index (int i)
    {
    return m[i];
    }

MN& intersec(const MN &x,int n,int l)
{ int i,j,r,k;
int lenc=0;
MN c(lenc);
if (n>l)
 k=n;
else k=l;
    for (i=0;i<k;i++)
  {for(j=0;j<k;j++)
{if (m[i]==x.m[j])
{c.m[r]=m[i];
lenc++;
r++;}
}}
for (i=0;i<lenc;i++)
    {
        cout<<c.m[i];
    }
//return c.m;
}

/*MN& print (int n)
{ int i;
    for (i=0;i<n;i++)
    {
        cout<<y.m[i];
    }
}*/

};

MN::MN(int l)
{
    n=l;
    int i;
    for (i=0;i<n;i++)
    {cin >> m[i];}
}
/*MN& intersec(const MN &x,int n,int l)
{ int i,j,lenc,r,k;
MN c(lenc);
if (n>l)
 k=n;
else k=l;
    for (i=0;i<k;i++)
  {for(j=0;j<k;j++)
{if (m(i)== x.m(j))
{c.m[r]=m[i];
lenc=r;
r++;}
}}
}
*/
int main()
{int lena,lenb;
int k,i,r;
cin>>lena;
cin>>lenb;
/*if (lena>lenb)
k=lena;
else k=lenb;*/
MN a(lena);
MN b(lenb);
//MN c(r);
a.intersec(b,lena,lenb);
//c.print(r);

/*for (i=0;i<k;i++)
{for(j=0;j<k;j++)
{if (a.index(i)== b.index(j))
{c.index(r)=a.index(i);
r++;}
}}*/
//int s;
/*(for (i=0;i<k;i++)
{//s=c.index(i);
 cout<<c.index(i);}*/
return 0;
}
