
#include<iostream.h> 
#include<conio.h>

class Stack
{
int StackData[100],size,top; public:
Stack() {top=-1;}
void SetSize(int n) {size=n;} void Push(int x);
int Pop(void);
void Display(void);
};

void Stack::Push(int x)
{
if(top>=size-1)
{
cout<<"\n\t\tStack is over flow..."; 
getch();
}
else
{
top++; StackData[top]=x;
cout<<"\n\t\t"<<x<<" is pushed \n\n\n";
}
}

int Stack::Pop(void)
{
int x; if(top<=-1)
{
cout<<"\n\t\tStack is under flow"; return -9999;
}
else
{
x=StackData[top]; top--;
return x;
}
}
 
void Stack::Display(void)
{
if(top>=0)
{
cout<<"\nThe elements in stack."; cout<<"\n~~~~~~~~~~~~~~~~~~~~~~"; for(int i=top;i>=0;i--)
cout<<"\n\nDATA "<<i+1<<" = "<<StackData[i]; cout<<"\n\n\n\n Press any key to continue...";
}
else
{
cout<<"\nThe Stack is empty.";
}
}

int main()
{
Stack S; clrscr();
int option,n;
cout<<"\nEnter the size of stack [MAX=100] : "; cin>>n;
S.SetSize(n); do
{
clrscr();
cout<<"\n\t\tStack Operation"; cout<<"\n\t\t~~~~~~~~~~~~~~~"; cout<<"\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT"; cout<<"\n\nEnter your option : ";
cin>>option; int x,topvalue; switch(option)
{
case 1: cout<<"\nEnter a value to be pushed : "; cin>>x;
S.Push(x);
S.Display(); break;
case 2: topvalue=S.Pop(); if (topvalue!=-9999)
cout<<"\n\t\t The popped element is "<<topvalue; S.Display();
break;
case 3: S.Display(); break;
case 4: cout<<"\n\n\t\t You are on EXIT..."; break; default:cout<<"\n\n\t Enter only 1,2,3,4.";
}
getch();
 
}while(option!=4); return 0;
}
