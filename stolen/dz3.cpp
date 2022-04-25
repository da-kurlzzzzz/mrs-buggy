#include <iostream>
#include "string.h"
#include <cstdio>
using namespace std;

class NODE
{static NODE *head;
NODE *next;
NODE *prev;
char info[40];
public: void Add_Info(char *ptr);
void Add_NODE();
void Display_All();};

NODE* NODE :: head=NULL;

void NODE :: Add_NODE()
{if (head==0)
{head=this;
next=prev=0;}
 else {next=head;
 head=this;
 next->prev=this;
 prev=0;
 }
}

void NODE:: Add_Info(char *ptr)
{strcpy (info, ptr);
next=prev=0;}

void NODE :: Display_All()
{NODE *cur=this;
while (cur!=head)
{cout<<cur->info<<'\n';
cur=cur->prev;}
cout<<cur->info<<'\n';
//cur->prev=this;
}

int main()
{char buf [255]="aaaaaa";
char *p;
int n;
NODE y;
p=gets(buf);
y.Add_Info(p);
y.Add_NODE();
//NODE r=this;
int flag=0;
//do //while (!strlen (buf))
//{//while (*gets (buf)!='\n')
//n=strlen (buf);
//p=gets(buf);
//if (fgets(buf, sizeof buf, stdin)!= NULL)

// while (flag==0)
 /*if (fgets(buf, sizeof buf, stdin)!= NULL)

    {NODE x;
x.Add_Info(buf);
x.Add_NODE();}*/
while (strlen(buf))
{
gets(buf);
NODE *x = new NODE;
x->Add_Info(buf);
x->Add_NODE();} //else flag ++;}
//puts(buf);}
//else { flag++;}}
//*r=head;}
//if (strcmp(buf, "\n") == 0)
    //break;
//while (n!=0)
//gets(buf);
//x.Add_Info(p);
//x.Add_NODE();}
//NODE x;
//if(*gets (buf)='\n')
/*NODE x;
x.Add_Info(buf);
x.Add_NODE();
r=x.this;
//y.Display_All();
//if (strlen(buf)!=0) break;*/
//} while (1);
//else
y.Display_All();
//y.Display_All();
return 0;
}
