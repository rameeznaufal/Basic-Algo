#include<stdio.h>
#include<stdlib.h>
struct node{
                  int key;
                  struct node *next;
                  struct node *prev;
                  };

typedef struct node *nde;

struct linkedlist {
                    nde head;
                    };     

int delete_f(struct linkedlist *l);
int delete_l(struct linkedlist *l);
nde create(int k)
{  nde temp;
   temp=(nde)malloc(sizeof(struct node));
   if(temp==NULL)
    {exit(0);} 
   temp->key=k;
   temp->next=NULL;
   temp->prev=NULL;
   return temp;
}                              

void insert_f(struct linkedlist *l,struct node x)
{nde temp;
 temp=create(x.key);
 temp->next=l->head;
 if(l->head!=NULL)
 l->head->prev=temp;
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
  temp->prev=p;
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
  if(p->next==NULL)
   insert_t(l,x);
   else
   {
  temp=create(x.key);
  temp->next=p->next;
  temp->prev=p;
  temp->next->prev=temp;
  p->next=temp;}}
  
void insert_b(struct linkedlist *l,struct node x,struct node y)
{nde p,temp;
 p=l->head;
 if(p->key==y.key)
  {temp=create(x.key);
   temp->next=p;
   l->head->prev=temp;
   l->head=temp;}
 else
 {while(p->next->key!=y.key)
 {p=p->next;}
  if(p->next->next==NULL)
  {temp=create(x.key);
  temp->next=p->next;
  temp->prev=p;
  p->next=temp;}
  else{
  temp=create(x.key);
  temp->next=p->next;
  temp->prev=p;
  temp->next->prev=temp;
  p->next=temp;}
 }
} 
int delete(struct linkedlist *l,struct node x)
{nde temp,p;
 int v;
 temp=search(*l,x.key);
 if(temp==NULL)
 return -1;
 if(temp->prev==NULL&&temp->next==NULL)
 {free(temp);
  l->head=NULL;
 return x.key;}
 else if(temp->prev==NULL)
 {v=delete_f(l);
  return v;}
 else if(temp->next==NULL)
 {v=delete_l(l);
 return v;}
 else
 {
 p=temp;
 temp->prev->next=temp->next;
 temp->next->prev=temp->prev;
 free(p);
 return x.key;}
 }
 
int delete_f(struct linkedlist *l)
{int y;
 nde p;
 if(l->head!=NULL)
 {y=l->head->key;
  p=l->head;
  l->head=l->head->next;
  l->head->prev=NULL;
  free(p);
  return(y);}
  else
   return -1;}
   
int delete_l(struct linkedlist *l)
{nde p;
 int y;
 p=l->head;
 if(p==NULL)
  return -1;
 while(p->next!=NULL)
  {p=p->next;}
  y=p->key;
  if(p->prev!=NULL)
  {p->prev->next=NULL;}
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
   
 
  
  
  
 
                  
