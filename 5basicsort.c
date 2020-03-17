#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int copy(int *);
int creation();
int increase(int);
int decrease(int);
int almostsorted(int);
int random1(int);
int bubblesort1();
int selection();
int insertion();
int shell();
int bucketsort();
int display(int*);
int a[1000000],b[1000000];
int n;
clock_t start,end;
double timeis;

void main()
{
int m;
printf("enter no. of elements in array :");
scanf("%d",&n);
do
{
printf("\n Menu: 1:bubble sort 2:seletion 3:insertion 4:shell  5: bucket  0:exit  : ");
scanf("%d",&m);
switch(m)
{
case 1:bubblesort1();break;;
case 2:selection();break;
case 3:insertion();break;
case 4:shell();break;
case 5:bucketsort();break;
case 0:exit(0);
}
copy(a);
}while(m!=0);
}

int creation()
{
int c;
printf("\ncreate array with elements in\n1:increasing order  2:decreasing order  3:almost sorted order  4: random order : ");
scanf("%d",&c);
switch(c)
{
case 1:increase(n);break;
case 2:decrease(n);break;
case 3:almostsorted(n);break;
case 4:random1(n);break;
}
}
int increase(int n)
{
int i;
for(i=0;i<n;i++)
{
a[i]=a[i-1]+2;
}
printf("before sorting \n");
display(a);
copy(a);
}
int decrease(int n)
{int i,t;
t=n;
for(i=0;i<n;i++)
{
a[i]=t;
t--;
}
printf("before sorting \n");
display(a);
copy(a);
}
int almostsorted(int n)
{
	int q,i;
	printf("enter the interval:");
	scanf("%d",&q);
	a[0]=6;
	for(i=0;i<n;i++)
	{
		a[i+1]=a[i]+6;
	}
	if(q>n)
	{
		printf("the list cannot be created");
	}
	else
	{
		for(i=q-1;i<n;i=i+q)
		{
			a[i]=rand()%10000;
		
		}
	}
printf("before sorting \n");
display(a);
copy(a);
}

int random1(int n)
{
int i;
for(i=0;i<n;i++)
{
a[i]=rand()%100000;
}
printf("before sorting \n");
display(a);
copy(a);
return 0;
}
int copy(int a[])
{
	int i;
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	return 0;
}

int display(int a[])
{
int i;
printf(" array is\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
}

int bubblesort1()
{
int i,j,t;
 printf("\t\t\t\tBUBBLE SORT");
 creation();
start=clock();
for(i=0;i<n;i++)
{
for(j=n-1;j>=i+1;j--)
{
if(b[j]<b[j-1])
{
t=b[j];
b[j]=b[j-1];
b[j-1]=t;
}
}
}
end=clock();
timeis=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nafter sorting \n");
display(b);
printf("\n%lf time\n",timeis);
}

int selection()
{	
int i,min,j,t;
  printf("\t\t\t\tSELECTION SORT");
 creation();
start=clock();
for(i=0;i<n-1;i++)
{
	min=i;
	for(j=i+1;j<n;j++)
	{
		if(b[j]<b[min])
		min=j;
	}
	if(min!=i)
	{
		t=b[min];
		b[min]=b[i];
		b[i]=t;
	}
}end=clock();
timeis=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nafter sorting \n");
display(b);
printf("\n%lf time\n",timeis);
}

int insertion()
{
	int i,j,k,t;
	  printf("\t\t\t\tINSERTION SORT");
	 creation();
	start=clock();
	for(i=1;i<=n-1;i++)
	{ 
	    	k=i;
		while(k>0 && b[k-1]>b[k])
		{
		t=b[k];
		b[k]=b[k-1];
		b[k-1]=t;
		k--;
	   }
	}
	end=clock();
timeis=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nafter sorting \n");
display(b);
printf("\n%lf time\n",timeis);
}

int shell()
{
int gap,temp,i,j;
  printf("\t\t\t\tSHELL SORT");
 creation();
start=clock();
for(gap=n/2;gap>0;gap/=2)
{
for(i=gap;i<n;i++)
{
for(j=i-gap;j>=0;j-=gap)
{
if(b[j+1]>=b[j])
break;
else 
{
temp=b[j];
b[j]=b[j+1];
b[j+1]=temp;	
}
}
}
}
end=clock();
timeis=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nafter sorting \n");
display(b);
printf("\n%lf time\n",timeis);
}

int bucketsort()
{
int c[10],j,i,n=10,k,y,z,bucket[10][10];
  printf("\t\t\t\tBUCKET SORT");
printf("\nEnter 10 elements for sorting");
for(i=0;i<10;i++)
{
    scanf("%d",&c[i]);
}
start=clock();
for(i=0;i<10;i++)
{
 for(j=0;j<10;j++)
 {
 bucket[i][j]=0;
 }
}
for(i=0;i<10;i++)
{
 j=0;
 k=c[i]/10;
 lab:
 if(bucket[k][j]==0)
  {
   bucket[k][j]=c[i];
  }
 else
   {
    j=j+1;
    goto lab;
   }
}
for(z=0;z<10;z++)
{
    for (i = 0 ; i < n - 1; i++)
  {
    for (j= 0 ; j < n - i - 1; j++)
    {
      if(bucket[z][j+1]==0)
       break;
      if (bucket[z][j] > bucket[z][j+1])
      {
        y       = bucket[z][j];
        bucket[z][j]   = bucket[z][j+1];
        bucket[z][j+1] = y;
      }
    }
  }
}
end=clock();
for(i=0;i<10;i++)
{
for(j=0;j<10;j++)
{
  if(bucket[i][j]!=0)
 {printf("%d\t",bucket[i][j]);}
}
}
timeis=(double)(end-start)/CLOCKS_PER_SEC;
printf("\n%lf time\n",timeis);
}
 
