#include<stdio.h>
#include<stdlib.h>

struct node
 {long int key;
  struct node *p,*l,*r;
 };

typedef struct node *node_ptr;

struct BST
    {
      node_ptr root;
    };

node_ptr create(long int k)
{node_ptr temp;
temp=(node_ptr)malloc(sizeof(struct node));
temp->key=k;
temp->p=temp->l=temp->r=NULL;
return temp;
}

void insert(struct BST *T,node_ptr x)
{node_ptr y=NULL,z;
z=T->root;
while(z!=NULL)
{ y=z;
 if(z->key>x->key) 
   z=z->l;
 else
   z=z->r;
}
x->p=y;
if(y==NULL)           // if T was empty
 T->root=x;
 else if(x->key>y->key)
  y->r=x;
  else
  y->l=x;
}

node_ptr tree_min(node_ptr x)
{while(x->l!=NULL)
{x=x->l;}
return x;
}

void transplant(struct BST *T,node_ptr x,node_ptr y)
{if(x->p==NULL)
  T->root=y;
  else
  {if(x->p->l==x)
   x->p->l=y;
   else
   x->p->r=y;}
 if(y!=NULL)
 {y->p=x->p;}
}   

node_ptr search(struct BST T,long int k)
{node_ptr y;
 y=T.root;
while(y!=NULL&&y->key!=k)
 {if(y->key>k)
   y=y->l;
   else
   y=y->r;   
 }
 return y;
}

void inorder(node_ptr T)
{if(T!=NULL)
 {inorder(T->l);
  printf("%ld ",T->key);
  inorder(T->r);}
}

void preorder(node_ptr T)
{if(T!=NULL)
 {printf("%ld ",T->key);
  preorder(T->l);
  preorder(T->r);}
}


void postorder(node_ptr T)
{if(T!=NULL)
 {postorder(T->l);
  postorder(T->r);
  printf("%ld ",T->key);}
}

void delete(struct BST *T,node_ptr x)
{node_ptr z;
  if(x->l==NULL)
   transplant(T,x,x->r);
  else if(x->r==NULL)
   transplant(T,x,x->l);
  else
  {z=tree_min(x->r);
   if(z->p!=x)
    {transplant(T,z,z->r);
     z->r=x->r;
     z->r->p=z;}  
  transplant(T,x,z);
  z->l=x->l;
  z->l->p=z;}
}

void main()
{struct BST T;
node_ptr x;
long int y;
T.root=NULL;
char a;
do
{scanf("%c",&a);
switch(a)
{case 'a':scanf("%ld",&y);
          x=create(y);
          insert(&T,x);
 break;
 case 'd':scanf("%ld",&y);
          x=search(T,y);
          if(x==NULL)
           printf("-1\n");
          else
           {printf("%ld\n",x->key);       
          delete(&T,x);}
 break;
 case 's':scanf("%ld",&y);
          x=search(T,y);
          if(x==NULL)
           printf("-1\n");
          else
           printf("1\n");           
 break;
  case 'i':inorder(T.root);
           printf("\n");
 break;
  case 'p':preorder(T.root);
           printf("\n");
 break;
  case 't':postorder(T.root);
           printf("\n");
 break;}
} while (a!='e');

}
