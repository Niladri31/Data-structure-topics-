#include<stdio.h>
#include<stdlib.h>

struct node *create2(struct node*,int);
struct node *create(struct node*,int);
struct node *insert2(int);

void preorder( struct node*);
void inorder(struct node*);
void postorder( struct node*);
int totalinternalnodes(struct node*);
int height(struct node *);
void traversal(struct node *);
void operation(struct node *);
int arr[8]={10,7,15,5,8,3,9,6},i=0;

struct node *temp=NULL,*x;

struct node
{
int data;
struct node *llink,*rlink;
};

void main()
{
int c;
struct node *root=NULL;

do{
printf("enter 1:creation without array list   2:creation using array list  0: exit   :");
scanf("%d",&c);
switch(c)
{

case 1:

root=create(root,10);
root->llink=create(root,7);
root->rlink=create(root,15);
root->llink->llink=create(root,5);
root->rlink->llink=create(root,8);
root->rlink->rlink=create(root,3);
root->llink->llink->rlink=create(root,9);
root->rlink->llink->rlink=create(root,6);
operation(root);
break;
case 2:  

root=create2(root,i);

operation(root);
break;
case 0:exit(0);
}
}while(c!=0);
}


void operation(struct node*root)
{
int x,i,j,t;
do{
printf("\nenter 1:traversal   2:to count the number of internalnodes   3:calculate height    0:for creation   :");
scanf("%d",&t);
switch(t)
{
case 1:traversal(root);break;
case 2:i=totalinternalnodes(root);printf("\nthe number of internal nodes in the tree is %d",i);break;
case 3:j=height(root);printf("\nthe height is %d",j);break;

case 0:main();
}
}while(t!=0);
}


void traversal(struct node *root)
{
int x;

do
{
printf("\nenter the type of traversal you want to perform:\n 1.preorder 2.inorder 3.postorder 0.for other operation  :");
 scanf("%d",&x);
 switch(x)
 {
 case 1:preorder(root);break;
 case 2:inorder(root);break;
 case 3:postorder(root);break;
 case 0:operation(root);
 }
 }while(x!=0);
 }
  
  struct node *create(struct node *r,int info)
  {
  r=(struct node*) malloc(sizeof (struct node));
  r->llink=NULL;
  r->data=info;
  r->rlink=NULL;
   return r;
   }
   
  
 void preorder(struct node *root)
 {
 if(root!=NULL)
{
 printf("%d\t",root->data);
 preorder(root->llink);
 preorder(root->rlink);
}
 }
 
 void inorder(struct node *root)
 { if(root!=NULL)
{
 inorder(root->llink);
  printf("%d\t",root->data);
 inorder(root->rlink);
}
 }

 
 void postorder(struct node *root)
 {
  if(root!=NULL){
 postorder(root->llink);
 postorder(root->rlink);
  printf("%d\t",root->data);
}
 }

int totalinternalnodes(struct node *r)
{
if(r==NULL)
return 0;
if(r->llink==NULL && r->rlink==NULL)
return 0;
else
return totalinternalnodes(r->llink)+totalinternalnodes(r->rlink)+1;
}


int height(struct node *r)
{
int lheight,rheight;
if(r==NULL)
return 0;
else
{
lheight=height(r->llink);
rheight=height(r->rlink);
}
if(lheight>rheight)
return lheight+1;
else
return rheight+1;
}



struct node* create2(struct node *root,int i)
{
if(i<8)
{
x=insert2(arr[i]);
root=x;
root->llink=create2(root->llink,2*i+1);
root->rlink=create2(root->rlink,2*i+2);
}
return root;
}


struct node* insert2(int data)
{
x=(struct node *)malloc(sizeof(struct node));
x->data= data;
x->llink = NULL;
x->rlink = NULL;
return(x);
}













