#include<stdio.h>
#include<stdlib.h>
void stack();
int queue();
void cirqueue();
void push(int *,int* );
int pop(int*,int *);
void traverses(int *,int* );
void traverseq(int *,int* ,int* );
int insertion(int* ,int* ,int* );
int deletion(int *,int*,int* );
void addq(int *,int *,int *);
void delq(int*,int *,int *);
void traversec(int *,int *,int * );
int a[10000],n;

void main()
{
int c;
do{
printf("\nenter the data structure you want to implement  1:stack  2:queue  3:circular queue  0:exit  :");
scanf("%d",&c);
switch(c)
{
case 1:stack();break;
case 2:queue();break;
case 3:cirqueue();break;
case 0:exit(0);
}
}while(c!=0);
}

void stack()
{
int s,b,i,j;
n=0;
int top=-1;
printf("\nenter the size of stack   :");
scanf("%d",&n);
for(j=0;j<n;j++)
a[j]=0;

do{
printf("\nenter the operation you want to perform  1:push 2:pop 3:display 0:for other data structures   :");
scanf("%d",&s);
switch(s)
{
case 1:push(a,&top);
break;
case 2:
pop(a,&top);break;
case 3:traverses(a,&top);break;
case 0:main();
break;	 
}
}while(s!=0);
}

void push(int a[],int *top)
  {  
int b;
  if(*top==n-1)
  {
  printf("stack is full");
}
  else
{
printf("enter the element to push in the stack   :");
scanf("%d",&b);
(*top)++;
  a[*top]=b;
  }
}
  
  
int pop(int a[],int *top)
  {
  int num;
  if(*top==-1)
  {
printf("stack is empty");

}
else 
{
num=a[*top];
(*top)--;
}

printf("item popped is %d",num);
}

void traverses(int a[],int *top)
{
int i;
for(i=*top;i>=0;i--)
{
printf("%d\t",a[i]);
}

printf("\ntop is ");
                                                                                                     
printf("%d",a[*top]);
}



int queue()
{
int q,i;
int front=-1,rear=-1;
n=0;
printf("enter the size of queue  :");
scanf("%d",&n);
for(i=0;i<n;i++)
{
a[i]=0;
}

do{
printf("\nenter the operation you what to perform  1:insertion  2:deletion   3:display  0:for other operations  :");
scanf("%d",&q);
switch(q)
{
case 1:insertion(a,&front,&rear);break;
case 2:deletion(a,&front,&rear);break;
case 3:traverseq(a,&front,&rear);break;
case 0:main();
}
}while(q!=0);
}

int insertion(int a[],int *front,int *rear)
{
int b;
if(*rear==n-1)
{
printf("queue is full");
} 
else if(*front=-1)
{
printf("enter the element to insert   : ");
scanf("%d",&b);
*front=0;
(*rear)++;
a[*rear]=b;
}
else
{
printf("enter the element to insert  :");
scanf("%d",&b);
(*rear)++;
a[*rear]=b;
}
}


int deletion(int a[],int *front,int *rear)
 {
 int num1;
 if(*front==-1)
 {
 printf("queue is empty");
 }
 num1=a[*front];
 a[*front]==0;
if(*front==*rear)
{
(*front)=-1;
(*rear)=-1;
}
else
(*front)++;
printf("item deleted is %d",num1);
 }
 

 void traverseq(int a[],int *front,int *rear)
 {
int j;
for(j=*front;j<=*rear;j++)
{
printf("%d\t",a[j]);
}
 printf("front is ");
printf("%d",a[*front]);
printf("\nrear is ");
printf("%d",a[*rear]);
}
 

void cirqueue()
{
	
int c,i;
int cfront=-1, crear=-1;
n=0;
printf("enter the size of circular queue  :");
scanf("%d",&n);
for(i=0;i<n;i++)
a[i]=0;
do{
printf("\nenter the operation you want to perform 1:insertion 2:deletion 3:traversal 0:for other data structures   :");
scanf("%d",&c);
switch(c)
{
	case 1:addq(a,&cfront,&crear);break;
	case 2:delq(a,&cfront,&crear);break;
	case 3:traversec(a,&crear,&cfront);break; 
        case 0:main();                                             
}
}while(c!=0);
}

void addq(int a[],int*cfront,int*crear)
{
int q;

if(((*cfront==0)&&(*crear==n-1))||(*crear==(*cfront-1)))
{
printf("Queue is Full\n");
return;
}

if(*cfront==-1 && *crear==-1)
{
*cfront=0;
*crear=0;
}
else if(*crear==n-1 && *cfront>0)
{
*crear=0;
}
else
{
(*crear)++;
}
printf("Enter Element to Insert : ");
scanf("%d",&q);
a[*crear]=q;
printf("Front=%d\nRear=%d\n",a[*cfront],a[*crear]);
}

void delq(int a[],int*cfront,int*crear)
{
if(*cfront==*crear)
{
if(*cfront==-1)
{
printf("Circular Queue is Empty\n");
}
else
{
*cfront=-1;
*crear=-1;
printf("Now Circular Queue is Empty\n");
}
}
else
{
if(*cfront==n-1)
{
*cfront=0;
printf("\nFront=%d\nRear=%d\n",a[*cfront],a[*crear]);
}
else if(*cfront<*crear)
{
(*cfront)++;
printf("\nFront=%d\nRear=%d\n",a[*cfront],a[*crear]);
}
}
}

void traversec(int a[],int *crear,int *cfront)
{    
int k,i;
printf("Circular Queue:\n");
if(*crear>=*cfront)
{
for(k=*cfront;k<=*crear;k++)
{
printf("%d\t",a[k]);
}
}
else
{
for(k=*cfront;k<n;k++)
{
printf("%d\t",a[k]);
}
for(k=0;k<=*crear;k++)
{
printf("%d\t",a[k]);
}
}
printf("\n");
printf("rear is : ");
      printf("%d\n",a[*crear]);
         printf("front is : ");
   printf("%d",a[*cfront]);
}




