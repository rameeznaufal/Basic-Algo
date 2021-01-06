#include<stdio.h>
#include<stdlib.h>
struct node{
                  int key;
                  struct node *next;
                  };

typedef struct node *nde;

struct linkedlist {
                    nde head;
                    };     


nde create(int k)
{  nde temp;
   temp=(nde)malloc(sizeof(struct node));
   if(temp==NULL)
    {exit(0);} 
   temp->key=k;
   temp->next=NULL;
   return temp;
}                              

void insert_f(struct linkedlist *l,struct node x)
{nde temp;
 temp=create(x.key);
 temp->next=l->head;
 l->head=temp;
 }
 
void insert_t(struct linkedlist *l,struct node x)
{nde temp,p;
 temp=create(x.key);
 p=l->head;
 if(l->head==NULL)
   l->head=temp;
 else
 {while(p->next!=NULL)
  {p=p->next;}
  p->next=temp;}
}

nde search(struct linkedlist l,int k)
{nde p;
 p=l.head;
 while(p!=NULL)
 {if(p->key==k)
   {return p;}
  p=p->next;
 }
 return NULL;
 }
 
void insert_a(struct linkedlist *l,struct node x,struct node y)
 {nde p,temp;
  p=search(*l,y.key);
  temp=create(x.key);
  temp->next=p->next;
  p->next=temp;}
  
void insert_b(struct linkedlist *l,struct node x,struct node y)
{nde p,temp;
 p=l->head;
 if(p->key==y.key)
  {temp=create(x.key);
   temp->next=p;
   l->head=temp;}
 else
 {while(p->next->key!=y.key)
 {p=p->next;}
  temp=create(x.key);
  temp->next=p->next;
  p->next=temp;}
 }
 
int delete(struct linkedlist *l,struct node x)
{nde temp,p;
 temp=l->head;
 if(temp==NULL)
  return -1;
 if(temp->key==x.key)
 {l->head=l->head->next;
  free(temp);
  return x.key;}
 
  while((temp->next!=NULL)&&(temp->next->key!=x.key))
 {temp=temp->next;}
  if(temp->next==NULL)
  return -1;
  p=temp->next;
 temp->next=temp->next->next;
 free(p);
 return x.key;
 }
 
int delete_f(struct linkedlist *l)
{int y;
 nde p;
 if(l->head!=NULL)
 {y=l->head->key;
  p=l->head;
  l->head=l->head->next;
  free(p);
  return(y);}
  else
   return -1;}
   
int delete_l(struct linkedlist *l)
{nde p,q;
 q=NULL:
 int y;
 p=l->head;
 if(p==NULL)
  return -1;
 while(p->next!=NULL)
  {q=p;
   p=p->next;}
  y=p->key;
  if(q!=NULL)
  {q->next=NULL;}
  if(p==l->head)
   l->head=NULL;
 free(p);
 return y;
 }
 
 
 void main() 
{char c;
 int x,y;
 struct node n,m;
 struct linkedlist l;
 l.head=NULL;
 do{ scanf("%c",&c);
  switch(c)
  {case 'f':scanf("%d",&x);
            n.key=x;
            insert_f(&l,n);
   break;
   case 't':scanf("%d",&x);
            n.key=x;
            insert_t(&l,n);
   break;
   case 'a':scanf("%d",&x);
            scanf("%d",&y);
            m.key=y;
            n.key=x;
            insert_a(&l,n,m);
   break;
   case 'b':scanf("%d",&x);
            scanf("%d",&y);
            n.key=x;
            m.key=y;
            insert_b(&l,n,m);
   break;
   case 'd':scanf("%d",&x);
            n.key=x;
            y=delete(&l,n);
            printf("%d\n",y);
   break;
   case 'i':x=delete_f(&l);
            printf("%d\n",x);
   break;
   case 'l':x=delete_l(&l);
            printf("%d\n",x);
   break;
   case 's':scanf("%d",&x);
            if(search(l,x))
            printf("1\n");
            else
            printf("-1\n");
   break;
   }
  }while(c!='e');
 } 
   
 
  
  
  
 
                  
