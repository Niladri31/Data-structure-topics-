#include<stdio.h>
#include<stdlib.h>
#define MAX_Q_SIZE 50
#include"dspd7.h"


struct node *insert(struct node *,int);
struct node *delete(struct node *,int);
struct node *findlargestnode(struct node *);
void levelorder(struct node *);
struct node** createQueue(int *, int *); 
void enQueue(struct node **, int *, struct node *); 
struct node *deQueue(struct node **, int *); 
void main()
{
int o,key,key1;
do{
printf("\nenter the operation you want to perform  1:insertion  2:deletion   3:level order traversal   4:traversal   0:exit  : ");
scanf("%d",&o);
switch(o)
{
case 1:printf("enter the value to be inserted :  ");
scanf("%d",&key);
root=insert(root,key);
break;

case 2:printf("enter the value to be deleted :  ");
scanf("%d",&key1);
root=delete(root,key1);break;
case 3:levelorder(root);break;
case 4:traversal(root);break;
case 0:exit(0);
}
}while(o!=0);
}




void levelorder(struct node* root) 
{ 
    int rear, front; 
    struct node **queue = createQueue(&front, &rear); 
    struct node *temp_node = root; 
  
    while (temp_node) 
    { 
        printf("%d ", temp_node->data); 
  
 
        if (temp_node->llink) 
            enQueue(queue, &rear, temp_node->llink); 
  
     
        if (temp_node->rlink) 
            enQueue(queue, &rear, temp_node->rlink); 
  
     
        temp_node = deQueue(queue, &front); 
    } 
} 

struct node** createQueue(int *front, int *rear) 
{ 
    struct node **queue = (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE); 
  
    *front = *rear = 0; 
    return queue; 
} 
  
void enQueue(struct node **queue, int *rear, struct node *new_node) 
{ 
    queue[*rear] = new_node; 
    (*rear)++; 
} 
  
struct node *deQueue(struct node **queue, int *front) 
{ 
    (*front)++; 
    return queue[*front - 1];
}


struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
                        malloc(sizeof(struct node)); 
    node->data = data; 
    node->llink = NULL; 
    node->rlink = NULL; 
  
    return(node); 
}


struct node* insert(struct node* node, int key)
{
if(node == NULL)
{
struct node *node = (struct node*)malloc(sizeof(struct node));
node->data=key;
node->llink=node->rlink = NULL;
return node;
}
if (key < node->data)
node->llink = insert(node->llink,key);
else if (key > node->data)
node->rlink = insert(node->rlink,key);
return node;
}



struct node* delete(struct node* tree,int val)
{
struct node *temp=NULL;
if(tree==NULL)
{
printf("%d not found",val);
}
else if(val<tree->data)
{
delete(tree->llink,val);
}
else if(val>tree->data)
{
delete(tree->rlink,val);
}
else if(tree->llink && tree->rlink)
{
temp=findlargestnode(tree->llink);
tree->data=temp->data;
delete(tree->llink,temp->data);
}
else
{
temp=tree;
if(tree->llink==NULL && tree->rlink==NULL)
{
tree==NULL;
}
else if(tree->llink!=NULL)
{
tree=tree->llink;
}
else
{
tree=tree->rlink;
}
}
free(temp);
return tree;
}


struct node* findlargestnode(struct node *tree)
{
if(tree==NULL || tree->rlink==NULL)
return tree;
else
return findlargestnode(tree->rlink);
}




