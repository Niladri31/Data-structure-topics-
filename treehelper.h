struct node
{
int data;
struct node *llink,*rlink;
};
struct node *root=NULL;


void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);




void traversal()
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

 }
 }while(x!=0);
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

