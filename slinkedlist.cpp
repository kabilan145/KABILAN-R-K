#include<iostream.h> 
#include<conio.h>

typedef struct node
{
int data;
struct node *link;
};
 
class LinkedList
{
node *Head; public:
LinkedList(){Head=NULL; }
~LinkedList(){delete Head;} 
void Append(int x);
void AddAfter(int loc,int x); 
void AddAtBegin(int x); void Display();
void Count(); void Delete(int x);
};

void LinkedList::Append(int num)
{
node *temp,*r; temp=Head;

if(Head==NULL)
{
temp=new node; temp->data=num; temp->link=NULL; Head=temp;
}
else
{
while(temp->link!=NULL) temp=temp->link;
r=new node;
r->data=num; r->link=NULL; temp->link=r;
}
}

void LinkedList::AddAfter(int loc,int num)
{
node *temp,*r; int i; temp=Head; if(temp==NULL)
{
cout<<"\n\n\t\t There are less than "<<loc<<" elements in list."; return;
}
for(i=0;i<loc-1;i++)
{
if(temp==NULL)
 
{
cout<<"\n\n\t\tThere are less than "<<loc<<" elements in list."; return;
}
temp=temp->link;
}
r=new node;
r->data=num;
r-	>link=temp->link; temp->link=r;
}

void LinkedList::AddAtBegin(int num)
{
node *temp; temp = new node;
temp->data=num; temp->link=Head; Head=temp;
}

void LinkedList::Display()
{
cout<<"\n\n\n"; node *temp=Head; while(temp!=NULL)
{
cout<<temp->data<<" --> "; temp=temp->link;
}
cout<<"NULL"; getch();
}

void LinkedList::Count()
{
int c=0;
node *temp=Head; while(temp!=NULL)
{
temp=temp->link; c++;
}
cout<<"\n\n\n\t\tCount = "<<c;
}
 
void LinkedList::Delete(int num)
{
node *old,*temp; temp=Head; while(temp!=NULL)
{
if(temp->data==num)
{
if(temp==Head)
{
Head=temp->link; delete temp; return;
}
else
{
old->link=temp->link; delete temp;
return;
}
}
else
{
old=temp; temp=temp->link;
}
}
cout<<"\n\n\n\t\tThe data not found.";
}

int main()
{
LinkedList L; int choice,x,loc;

do
{
clrscr();
cout<<"\n\t\t\tSingle Linked List"; cout<<"\n\t\t\t~~~~~~~~~~~~~~~~~~"; cout<<"\n\t1. CREATE A NODE"; cout<<"\n\t2. ADD AT THE BEGINING";
cout<<"\n\t3. ADD AT END";
cout<<"\n\t4. ADD AFTER A SPECIFIC LOCATION";
cout<<"\n\t5. DISPLAY "; cout<<"\n\t6. COUNT NO OF NODES";
cout<<"\n\t7. DELETE A SPECIFIED NODE";
cout<<"\n\t8. EXIT"; cout<<"\n\n\nEnter your choice : "; cin>>choice;
 
switch(choice)
{
case 1 :
cout<<"\n Enter a value : "; cin>>x;
L.Append(x);
L.Display(); break;
case 2 :
cout<<"\n Enter a value : "; cin>>x;
L.AddAtBegin(x); L.Display(); break;
case 3 :
cout<<"\n Enter a value : "; cin>>x;
L.Append(x);
L.Display(); break;
case 4 :
cout<<"\n Enter the location : "; cin>>loc;
cout<<"\n Enter a value : "; cin>>x;
L.AddAfter(loc,x); L.Display(); break;
case 5 :
L.Display(); break;
case 6 :
L.Count();
L.Display(); break;
case 7 :
cout<<"\n Enter a value to delete : "; cin>>x;
L.Delete(x);
L.Display(); break;
case 8 :
cout<<"\n\n\n\t\t You are on Exit . . . "; getch();
break;
}
}while(choice!=8); return 0;
}
