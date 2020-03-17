#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int copy(int *);
int creation();
int increase(int);
int decrease(int);
int almostsorted(int);
int random1(int);
int quick1(int* ,int ,int);
int quick2(int* ,int ,int);
int partition1(int*,int ,int);
int partition2(int*,int ,int);
int mergesort(int*,int,int);
int merge(int*,int,int,int);
int display(int*);
void menu(int *,int,int);

int a[1000000],b[1000000];
int n;
clock_t start,end;
double timeis;

int main()
{
int m;
printf("\nenter no. of elements in array :");
scanf("%d",&n);
do
{
printf("\n Menu: 1:quick sort 2:merge sort 3:display 0:exit    :");
scanf("%d",&m);
switch(m)
{
case 1:	start=clock();
menu(a,0,n-1);
	end=clock();

	timeis=(double)(end-start)/CLOCKS_PER_SEC;
printf("\n%lf time\n",timeis);break;
case 2:
 creation();
 start=clock();
 mergesort(a,0,n-1);
 end=clock();
	timeis=(double)(end-start)/CLOCKS_PER_SEC;	
printf("\n%lf time\n",timeis);break;
case 3:display(a);break;
case 0:exit(0);
}
}while(m!=0);
copy(a);
return 0;
}

int creation()
{
int c;

printf("\ncreate array with  1:sorted elements  2:reverse sorted elements  3:almost sorted elements  4: random elements   :");
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
copy(a);
display(a);
}

int decrease(int n)
{int i,t;
t=n;
for(i=0;i<n;i++)
{
a[i]=t;
t--;
}
copy(a);
display(a);
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
copy(a);
display(a);
}

int random1(int n)
{
int i;
for(i=0;i<n;i++)
{
a[i]=rand()%100000;
}
copy(a);
display(a);
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
printf(" \narray is\n");
for(i=0;i<n;i++)
{
printf("\t%d",a[i]);
}
}
void menu(int a[],int p,int r)
{    int c;
creation();
		printf("\nenter the position you want to insert the pivot element 1:last   2:first   :");
		scanf("%d",&c);
		
		switch(c)
		{
		case 1:start=clock();
		quick1(a,p,r);break;
	    end=clock();
		case 2:start=clock();
		quick2(a,p,r);break;
		end=clock();	
        }  
  }  
int quick1(int a[], int p,int r)
{
	int q,c;
	
	if(p<r)	
    {
      q=partition1(a,p,r);
      quick1(a,p,q-1);
      quick1(a,q+1,r);
    }


}
int quick2(int a[], int p,int r)
{
	int q,c;

	if(p<r)	
    {
      q=partition2(a,p,r);
      quick2(a,p,q-1);
      quick2(a,q+1,r);
    }

}
 int partition1(int a[],int p,int r)
{   
    int x,t,z,i,j;
	x=a[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<=x)
	   {
	   		i++;
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		
       }
    } 
    z=a[i+1];
    a[i+1]=a[r];
    a[r]=z;
   
    return i+1;  
 }
 int partition2(int a[],int p,int r)
 {
 	int x,t,z,i,j;
 	x=a[p];
 	i=r+1;
 	for(j=r;j>=p+1;j--)
 	{
 		if(a[j]>=x)
 		{
 			i--;
 			t=a[i];
 			a[i]=a[j];
 			a[j]=t;
		 }
	 }
	 z=a[i-1];
	 a[i-1]=a[p];
	 a[p]=z;
	 return i-1;
 }
 
 
 int mergesort(int a[],int p,int r)
 {   
 int q;
 	if(p<r)
 	{
 		q=(p+r)/2;
 		mergesort(a,p,q);
 		mergesort(a,q+1,r);
 		merge(a,p,q,r);
	 }


 }
 int merge(int a[],int p,int q,int r)
 {    
int i, j, k;

    int n1 = q - p + 1;
    int n2 =  r - q;
 	   
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (j = 0; j < n2; j++)
        R[j] = a[q + 1+ j];
 

    i = 0; 
    j = 0; 
    k = p; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
