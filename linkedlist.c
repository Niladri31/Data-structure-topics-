#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};

struct node *rear=NULL;
struct node *front=NULL;

void insert(int);
void delete( struct node **,int);
void reverse(struct node **);
void search(struct node *,int );
void sort(struct node * );
void merge(struct node *);
void merging(struct node **,struct node **,struct node **);
void llist();
void lstack();
void push(struct node **,int );
int pop(struct node **);
int lqueue();
void addq(int );
void delq();
void addend(struct node **,int);
void addatbeg(struct node **,int);
void addafter(struct node *,int,int);
void display(struct node *);
int count(struct node *);
void displayq();


struct node *p=NULL;
struct node *second=NULL;
struct node *third=NULL;
struct node *a=NULL;
struct node *z=NULL;
void main()
{
int l;

do{
 printf("enter 1:linked list   2:linked stack  3:linked queue  0:exit  :");
scanf("%d",&l);
switch(l)
{
case 1:llist();
case 2:lstack();
case 3:lqueue();
case 0:exit(0);
}
}while(l!=0);
}



void llist()
{
int m,x,d,s;

do{
printf("\n\nenter the operation you want to perform on linked list  1:insertion 2:deletion  3:reverse 4:searching 5:sort  6:merge    0:for other list  : ");
scanf("%d",&m);
switch(m)
{
case 1:printf("\n\nenter the element to be inserted: ");
scanf("%d",&x);
insert(x);break;
case 2:printf("\nenter the element to be deleted: ");
scanf("%d",&d);
delete(&p,d);
display(p);break;

case 3:reverse(&p);display(p);break;
case 4:printf("enter the element to search: ");
scanf("%d",&s);
search(p,s);break;
case 5:printf("sorted ");
sort(p);display(p);break;

case 6:merge(p);break;


case 0:main();
}
}while(m!=0);
}


void insert(int x)
{
int i,loc;
do{
printf("\n\nenter which end you want to insert  1:end   2:beginning   3:in between   0:for other operations :  ");
scanf("%d",&i);
switch(i)
{
case 1:addend(&p,x);display(p);llist();break;
case 2:addatbeg(&p,x);display(p);llist();break;
case 3:printf("\nenter the position you want to insert %d:  ",x);
scanf("%d",&loc);
addafter(p,x,loc);display(p);llist();break;
case 0:llist();
}
}while(i!=0);
}


void addend(struct node **q,int num)
{
struct node *temp,*r;

if(*q==NULL)
{
temp=(struct node *)malloc(sizeof (struct node));
temp->data=num;
temp->link=NULL;
*q=temp;
}
else
{
temp=*q;

while(temp->link!=NULL)
temp=temp->link;

r=(struct node *)malloc(sizeof (struct node));
r->data=num;
r->link=NULL;
temp->link=r;
}
}


void addatbeg(struct node **q,int num)
{
struct node *temp;
if(*q==NULL)
{
temp=(struct node *)malloc(sizeof (struct node));
temp->data=num;
temp->link=NULL;
*q=temp;
}
else
{
temp=(struct node *)malloc(sizeof(struct node));
temp->data=num;
temp->link=*q;
*q=temp;
}
}


void addafter(struct node *q,int num,int loc)
{
int i;
struct node *temp,*r;

if(q==NULL)
{
temp=(struct node *)malloc(sizeof (struct node));
temp->data=num;
temp->link=NULL;
q=temp;
}
temp=q;
for(i=0;i<loc;i++)
{
temp=temp->link;


if(temp==NULL)
{
printf("there are less than %d elements in list",loc);
return ;
}
}
r=(struct node*) malloc (sizeof(struct node));
r->data=num;
r->link=temp->link;
temp->link=r;
}



void display(struct node *q)
{
printf("\nlinked list is \n");
while(q!=NULL)
{
printf("%d\t",q->data);
q=q->link;
}
}



void delete(struct node **q,int num)
{
struct node *temp,*old;

temp=*q;

while(temp!=NULL)
{
if(temp->data==num) 
{
if(temp==*q)
*q=temp->link;
else
old->link=temp->link;
free(temp);
return ;
}
else{
old=temp;
temp=temp->link;
}
}
printf("element %d not found",num);
}



void reverse(struct node **x)
{
struct node *q,*r,*s;

q=*x;
r=NULL;
while(q!=NULL)
{
s=r;
r=q;
q=q->link;
r->link=s;
}
*x=r;
}


void search(struct node *q,int num)
{
struct node *temp;
int pos=0;
temp=q;
while(temp!=NULL)
{
if(temp->data==num)
{
printf("the element is found at pos %d ",pos);
return ;
}
temp=temp->link;
pos=pos+1;
}
if(temp==NULL){
printf("element %d not found ",num);
}

}




void sort(struct node *q)
{
  int i=0,t; 
    struct node *temp,*hold; 
hold=q;
int cnt=0;

while(hold!=NULL)
{
hold=hold->link;
cnt=cnt+1;
}

while(i<cnt-1)
{
temp=q;
while(temp->link !=NULL)
{
if((temp->data)>(temp->link->data))
{
t=temp->data;
temp->data=temp->link->data;
temp->link->data=t;
}
temp=temp->link;
}
i=i+1;
}
}

 
  

void merge(struct node *p)
{
struct node *second=NULL,*third=NULL;
int c,b;

printf("\nfor second linked list");
do{
printf("\n\n press 1:insertion of elements  0:merge : ");
scanf("%d",&c);
switch(c)
{
case 1:printf("\n\nenter the element to be inserted in second linked list: ");
scanf("%d",&b);
addatbeg(&second,b);
display(second);break;

case 0:break;

}
}while(c!=0);

printf("first  ");
display(p);
printf("\nthe number of elements in first linked list is :%d\n",count(p));
printf("\nsecond  ");
display(second);
printf("\nthe number of elements in second linked list is :%d\n",count(second));
merging(&p,&second,&third);
printf("merged");
display(third);
printf("\nthe number of elements in merged linked list is :%d\n",count(third));
}


void merging(struct node **p,struct node **second,struct node **third)
{
struct node *temp;
 
    if(*second==NULL && *p!=NULL) 
    {
        *third=*p;
        return ;
    }
 
    else if(*p==NULL && *second!=NULL)    
    {
        *third=*second;
        return ;
    }
 
    else if(*p==NULL && *second==NULL)
    {
        return ;
    }
    *third=*p;
    temp=*p;
    while(temp->link!=NULL)
{
        temp=temp->link;
}
        temp->link=*second;
}



int count(struct node *p)
{
int c=0;

while(p!=NULL)
{
p=p->link;
c++;
}
return c;
}




void lstack()
{
int s,l,i;

do{
printf("\nenter the operation you want to perform on stack 1:push  2:pop  0:for other list :   " );
scanf("%d",&s);
switch(s)
{
case 1:printf("enter the element you want to push  : ");
scanf("%d",&l);
push(&a,l);
display(a);
break;
case 2:i=pop(&a);
printf("item popped is %d",i);break;
case 0:main();
}
}while(s!=0);
}


void push(struct node **top,int num)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));

if(temp==NULL)
printf("stack is full");


temp->data=num;
temp->link=*top;
*top=temp;
}


int pop(struct node **top)
{
struct node*temp;
int num;
if(*top==NULL)
{
printf("stack is empty\n");

}
temp=*top;
num=temp->data;
*top=(*top)->link;
free(temp);
return num;

}


int lqueue()
{
int l,b,i;


do{
printf("enter the operation you want to perform queue 1:insertion  2:deletion  0:other list  :  ");
scanf("%d",&l);
switch(l)
{
case 1:printf("enter the element you want to push  : ");
scanf("%d",&b);
addq(b);displayq();break;
case 2:delq();
break;
case 0:main();
}
}while(l!=0);
}





void addq(int value)
{
   struct node *newnode;
   newnode = (struct node*) malloc(sizeof (struct node));
   newnode->data = value;
   newnode -> link = NULL;
   if(front == NULL)
      front = rear = newnode;
   else{
      rear -> link = newnode;
      rear = newnode;
   }
}


void delq()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct node *temp = front;
      front = front -> link;
      printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}



void displayq()
{   printf("Linked list is\n");
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct node *temp = front;
      while(temp->link != NULL){
	 printf("%d\t",temp->data);
	 temp = temp -> link;
      }
      printf("%d\t\n",temp->data);
   }
}






































