#include<stdio.h>
#include<stdlib.h>
struct node{
                  long int data;
                  struct node *next;
                  };

typedef struct node *nde;

struct stack{
                    nde top;
                    };     


nde create(long int k)
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
 

 
long int pop(struct stack *l)
{long int y;
 nde p;
 if(l->top!=NULL)
 {y=l->top->data;
  p=l->top;
  l->top=l->top->next;
  free(p);
  return(y);}
  else
   return -1;}
   

 
 
 void main() 
{char c;
 long int x;
 struct node n;
 struct stack l;
 l.top=NULL;
 do{ scanf("%c",&c);
  switch(c)
  {case 'i':scanf("%ld",&x);
            n.data=x;
            push(&l,n);
   break;
   case 'd':x=pop(&l);
            printf("%ld\n",x);
   break;
   case 'e':printf("%d\n",se(l));
   break;
   }
  }while(c!='t');
 } 
   
 
  
  
  
 
                  
