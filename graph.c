#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int a[10][10],n;
typedef struct Q
{
 int data[MAX];
 int R,F;
}Q;

typedef struct node
{
struct node *next;
int vertex;
}node;

int empty(int *);
void enqueue1(Q *,int);
int dequeue1(Q *);
int empty1(Q *);
void BFS(int);
void readgraph();      
void insert(int vi,int vj);     
void DFS(int i);
int visited2[MAX];
node *G[20];         
void display();
void dfs(int );
void createq();
void bfs(int x);
void enqueue(int x,int *);
int dequeue(int *);
int visited[10];
int visited1[10];
void adjmatrix();
void adjlist();
int front=-1,rear=-1;
void main()
{
int z;
do{

printf("\nenter the representation you want to perform  1:adjmatrix  2:adjlist  0:exit :  ");
scanf("%d",&z);
switch(z)
{
case 1:adjmatrix();break;
case 2:adjlist();break;
case 0:exit(0);
}
}while(z!=0);
}


void adjmatrix()
{
int a;
do{
printf("\nenter 1:display  2:dfs  3:bfs  0:exit  :");
scanf("%d",&a);
switch(a)
{
case 1:display();break;

case 2:dfs(0);break;

case 3:bfs(0);break;

case 0:main();
}
}
while(a!=0);
}



void display()
{

int i,j,c;
printf("enter number of vertices in the matrix :");
scanf("%d",&n);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("enter 1:to create edges of %d,%d  0:to not create  :",i,j);
scanf("%d",&c);
if(c==1)
{
a[i][j]=1;
}
else
{
a[i][j]=0;
}
}
printf("\n");
}
printf("adjencency matrix is \n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
}

 

void dfs(int x)
{
int i;

visited[x]=1;
printf("%d\t",x);
for(i=0;i<n;i++)
{
if(a[x][i]==1)
{
if(visited[i]==0)
{
dfs(i);
}
}
}
}



void bfs(int x)
{
int q[10],v,i;

visited1[x]=1;

enqueue(x,q);

while(empty(q)!=1)
{

v=dequeue(q);
printf("%d\t",v);
for(i=0;i<n;i++)
{
if(a[x][i]==1)
{
if(visited1[i]==0)
{
enqueue(i,q);
visited1[i]=1; 
}
}
}
x++;
}
}


void enqueue(int x,int q[])
{
int b;
if(rear==n-1)
{
printf("queue is full");
return ;
} 
(rear)++;
q[rear]=x;

if(front==-1)
front=0;
}


int dequeue(int q[])
{
int v;
if(front==-1)
{
printf("queue is empty");
}
v=q[front];
q[front]=0;
if(front==rear)
front=rear=-1;
else
(front)++;
return v;
}


int empty(int q[])
{
if(front==-1)
return 1;
else
return 0;
}


void adjlist()
{
 int i,op;
do
{ 
printf("\n\n1)Create\n2)BFS\n3)DFS\n0)Quit");
printf("\nEnter Your Choice: ");
scanf("%d",&op);
switch(op)
{ 
case 1: readgraph();break;
case 2: printf("\nStarting Node No. : ");
scanf("%d",&i);
BFS(i);break;
case 3:  for(i=0;i<n;i++)
visited[i]=0;
printf("\nStarting Node No. : ");
scanf("%d",&i);
DFS(i);break;
case 0:main();
}
}while(op!=0);
}


void BFS(int v)
{
 int w,i,visited2[MAX];
 Q q;
int x;
 node *p;
 q.R=q.F=-1;            
 for(i=0;i<n;i++)
  visited2[i]=0;
 enqueue1(&q,v);
printf("%d\n",v);
 visited2[v]=1;
while(!empty1(&q))
{
v=dequeue1(&q);

for(p=G[v];p!=NULL;p=p->next)
{
w=p->vertex;
if(visited2[w]==0)
{
enqueue1(&q,w);
visited2[w]=1;
printf("%d\n",w);
}
}
}
}

void DFS(int i)
{
 node *p;
 printf("\n%d",i);
 p=G[i];
 visited2[i]=1;
 while(p!=NULL)
 {
 i=p->vertex;
 if(!visited2[i])
  DFS(i);
 p=p->next;
 }
}


int empty1(Q *P)
{
 if(P->R==-1)
  return(1);
 return(0);
}

void enqueue1(Q *P,int x)
{
 if(P->R==-1)
 {
  P->R=P->F=0;
  P->data[P->R]=x;
 }
 else
 {
  P->R=P->R+1;
  P->data[P->R]=x;
 }
}

int dequeue1(Q *P)
{
 int x;
 x=P->data[P->F];
 if(P->R==P->F)
 {
  P->R=-1;
  P->F=-1;
 }
 else
  P->F=P->F+1;
 return(x);
}

void readgraph()
{  int i,vi,vj,no_of_edges;
 printf("\nEnter no. of vertices :");
 scanf("%d",&n);

 for(i=0;i<n;i++)
  G[i]=NULL;

 printf("\nEnter no of edges :");
 scanf("%d",&no_of_edges);
 for(i=0;i<no_of_edges;i++)
 {
  printf("\nEnter an edge (u,v)  :");
  scanf("%d%d",&vi,&vj);
  insert(vi,vj);
  insert(vj,vi);
 }
}

void insert(int vi,int vj)
{
 node *p,*q;
 
 q=(node *)malloc(sizeof(node));
 q->vertex=vj;
 q->next=NULL;

 if(G[vi]==NULL)
  G[vi]=q;
 else
 {
  p=G[vi];
  while(p->next!=NULL)
   p=p->next;
  p->next=q;
 }
}






