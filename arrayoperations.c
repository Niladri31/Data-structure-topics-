#include<stdio.h>
#include<stdlib.h>
int creation(int *); 
void traversal(int *);
void insertion(int *a);
void deletion(int *a);
void search(int *a);
void merge(int *a,int size);
int full(int size);
void length(int *);
int a[100],n;
void main()
{
int c;
creation(a);
do{
printf("\n1:traversal(a)  2:length(a) 3:insertion(a) 4:deletion(a) 5:searching(a) 6:merging(a)   0:exit\n");
printf("\nenter the choice:");
scanf("%d",&c);
switch(c)
{
case 1:traversal(a);break;
case 2:length(a);break;
case 3:insertion(a);break;
case 4:deletion(a);break;
case 5:search(a);break;
case 6:merge(a,n);break;
case 0:exit(0);
}
}
while(c!=0);
}
int creation(int a[])
{
	int i;
printf("\nenter the number of elements in the array: ");
scanf("%d",&n);	
printf("\nenter elements in array: ");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
return 0;
}

void traversal(int a[])
{
int i;
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
}

void insertion(int a[])
{ 
int new,pos,e,i;
e=full(n);
if(e==1 || e==2)
{
     printf("Enter the element to be inserted:");
     scanf("%d",&new);
     printf("Enter the position of element %d:",new);
     scanf("%d",&pos);
    for(i=n;i>=pos;i--)
   a[i]=a[i-1];
a[pos]=new;
n++;
traversal(a);
}

}

void deletion(int *a)
{
int pos,i,e;
e=full(n);
if(e==0 || e==2)
{
printf("enter position to delete:");
scanf("%d",&pos);
for(i=pos;i<n;i++)
{
a[i]=a[i+1];
}
n--;
traversal(a);
}

} 

void search(int *a)
{int srch,i;
printf("enter the element to search:");
scanf("%d",&srch);
for(i=0;i<n;i++)
{
if (a[i]==srch)
printf("%d is present at position %d",srch,i+1);
}
} 

void length(int *a)
{int q=0,i;
for(i=0;i<n;i++)
{
q++;
}
printf("length of array is %d",q);
}


int full(int size)
{
int f=0;
 if(size==100)
 { f=0;
  printf("the array is full\n");
 }
else if(size==0)
{  
    f=1;
	printf("Array is empty\n");
}
 else 
  {f=2;
  printf("array is not full\n");
  }
return f;
}


void merge(int *a, int size)
{
  int a2[10],s2=0,s,mer[15],i,j=0,k=0;
  printf("Enter the second array(elements<=10)press 99 at the end\n ");
  for(i=0;i<10;i++)
  {
    scanf("%d",&a2[i]);
    s2++;
    if(a[i]==99)
     break;
  }
  s=size+s2;
  for(i=0;i<s;i++)
  {  if(i<size)
     {
       mer[i]=a[j];
       j++;
     }
     else
     {
       mer[i]=a2[k];
       k++;
     }
  }s--;
  printf("New length of array is %d\nArray is:",s);
  for(i=0;i<s;i++)
  {
    printf("%d ",mer[i]);
  }printf("\n");


}
























