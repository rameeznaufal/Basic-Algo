#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
                  char data;
                  struct node *next;
                  };

typedef struct node *nde;

struct stack{
                    nde top;
                    };     


nde create(char k)
{  nde temp;
   temp=(nde)malloc(sizeof(struct node));
   if(temp==NULL)
    {exit(0);} 
   temp->data=k;
   temp->next=NULL;
   return temp;
}                              

void push(struct stack *l,struct node x)
{nde temp;
 temp=create(x.data);
 temp->next=l->top;
 l->top=temp;
 }
 

int se(struct stack l)
{if(l.top==NULL)
 return -1;
 else 
 return 1;
}
 
int pre(char a)
{if(a=='*'||a=='/')
 return 2;
 else if(a=='+'||a=='-')
  return 1;
  else if(a=='(')
  return 0;
  else
  return 0;
  }
 
char pop(struct stack *l)
{char y;
 nde p;
 if(l->top!=NULL)
 {y=l->top->data;
  p=l->top;
  l->top=l->top->next;
  free(p);
  return(y);}
  else
   return '\0';}
   
char* inf_to_post(char a[])
{struct stack s;
struct node x;
int pr,p;
int i=0;
s.top=NULL;
char *temp;                                  //temp is for saving the first address location
char *str=malloc(100*sizeof(char));
temp=str;
while(a[i]!='\0')
{if(isalpha(a[i]))
  {*(str++)=a[i];}
  else if(a[i]=='(')
   {x.data=a[i];
    push(&s,x);}
else if(a[i]==')')
  {x.data=pop(&s);
   
   while(s.top->data!='(')
   {*(str++)=x.data;
   x.data=pop(&s);}
  *(str++)=x.data;
  pop(&s);                    //to remove '('
  }
else 
{
 x.data=a[i];
if(s.top!=NULL)
 {while(pre(a[i])<=pre(s.top->data))
  {*(str++)=pop(&s);
   if(s.top==NULL)
   break;}
 } 
push(&s,x);
}
i++;}

while(s.top!=NULL)              //Incase if there r elements left in the stack
{*(str++)=pop(&s);}
*(str++)='\0';
str=temp;
return str;
}
 
 void main() 
{char c[100];
char *post;
scanf("%s",c);
post=inf_to_post(c);
while(*post!='\0')
{printf("%c",*(post++));}
 } 
   
 
  
  
  
 
           
                  
