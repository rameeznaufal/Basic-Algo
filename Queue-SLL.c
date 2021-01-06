#include<stdio.h>
#include<stdlib.h>
struct node{
                  long int data;
                  struct node *next;
                  };

typedef struct node *nde;

struct queue {
                    nde head,tail;
                    };     


int qe(struct queue l)
{if(l.head==NULL)
 return -1;
 else 
 return 1;
}

nde create(long int k)
{  nde temp;
   temp=(nde)malloc(sizeof(struct node));
   if(temp==NULL)
    {exit(0);} 
   temp->data=k;
   temp->next=NULL;
   return temp;
}                              

 
void enqueue(struct queue *l,struct node x)
{nde temp;
 temp=create(x.data);
 if(l->head==NULL)
   {l->head=temp;
    l->tail=temp;}
 else
 {l->tail->next=temp;
  l->tail=temp;}
}

 
long int dequeue(struct queue *l)
{long int y;
 nde p;
 if(l->head!=NULL)
 {y=l->head->data;
  p=l->head;
  l->head=l->head->next;
  free(p);
  return(y);}
  else
   return -1;}
   

  void main() 
{char c;
 long int x;
 struct node n;
 struct queue l;
 l.head=NULL;
 l.tail=NULL;
 do{ scanf("%c",&c);
  switch(c)
  {case 'i':scanf("%ld",&x);
            n.data=x;
            enqueue(&l,n);
   break;
   case 'd':x=dequeue(&l);
            printf("%ld\n",x);
   break;
   case 'e':printf("%d\n",qe(l));
   break;
   }
  }while(c!='t');
 } 
   

 
  
  
  
 
                  
