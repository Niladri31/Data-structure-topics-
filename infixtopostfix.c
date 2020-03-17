#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define n 1000
void convert();
void push(char);
char pop();
int type(char);
int precede(char);
void intopost();
void eval();
void cal();

int top=-1,k=0,m[100],z,v,w;
char a[n],infix[n],postfix[n],operand[n];

void main()
{
int b;
printf("Enter Infix Expression:");
scanf("%s",infix);
do
{
printf("Press For:\n1:Conversion of Infix to Postfix 2:Evaluation of Expression   0:Exit ");
scanf("%d",&b);
switch(b)
{
case 1:w=1;convert();
break;
case 2:v=1;eval();
break;
case 0:exit(0);
}
}
while(b!=0);
}

void convert()
{
if(v!=1)
{
intopost(infix,postfix);
}
printf("Postfix Expression:");
printf("%s",postfix);
printf("\n");
}

void push(char t)
{
if(top==n-1)
printf("Stack is Full\n");
else
{
top++;
a[top]=t;
}
}

char pop()
{
char t;
if(top==-1)
{
printf("Stack is Empty\n");
getchar();
exit(1);
}
else
{
t=a[top];
top--;
return(t);
}
}

int type(char sym)
{
if(sym=='^'||sym=='*'||sym=='/'||sym=='+'||sym=='-')
return 1;
else
return 0;
}


int preced(char sym)
{
if(sym=='^')
return 3;
else if(sym=='*'||sym=='/')
return 2;
else if(sym=='+'||sym=='-')
return 1;
else
return 0;
}


void intopost()
{
int i,j;
char t,x;
push('(');
strcat(infix,")");
i=0;j=0;
t=infix[i];
while(t!='\0')
{
if(t=='(')
push(t);
else if(isdigit(t)||isalpha(t))
{
postfix[j]=t;
operand[k]=t;
j++;
k++;
if(isalpha(t))
z=1;
}
else if(type(t)==1)
{
x=pop();
while(type(x)==1&&preced(x)>=preced(t))
{
postfix[j]=x;
j++;
x=pop();
}
push(x);
push(t);
}
else if(t==')')
{
x=pop();
while(x!='(')
{
postfix[j]=x;
j++;
x=pop();
}
}
else
{
printf("Invalid Expression\n");
getchar();
exit(1);
}
i++;
t=infix[i];
}
if(top>0)
{
printf("Invalid Expression\n");
getchar();
exit(1);
}

postfix[j]='\0';
}

void eval()
{
if(w!=1)
{
intopost(infix,postfix);
}
printf("Postfix Expression:");
printf("%s",postfix);
printf("\n");
if(z==1)
{
printf("Evaluation cannot be done.\n");
}
else
{
cal();
}
}

void cal()
{
int i,A,B,v;
char c;
for(i=0;postfix[i]!='\0';i++)
{
c=postfix[i];
if(isdigit(c))
{
push(c-'0');
}
else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
{
A=pop();
B=pop();
switch(c)
{
case'*':v=B*A;
break;
case'/':v=B/A;
break;
case'+':v=B+A;
break;
case'-':v=B-A;
break;
case'^':v=B^A;
}
push(v);
}
}
printf("Result of expression evaluation: %d\n",pop());
}



