#include<stdio.h>

struct queue{long int head,tail;
             long int a[100000];
             long int n;};
int qe(struct queue s)
{if(s.head==-1)
 return (-1);
 else 
 return 1;}
 
 int qf(struct queue s)
 {if(s.head==0&&s.tail==(s.n-1)||((s.tail+1)==s.head))
  return -1;
  else
  return 1;}
  
 void enqueue(struct queue *s,long int k)
 {if(qf(*s)!=-1)
  {if(qe(*s)==-1)
    {s->a[0]=k;
     s->head=s->tail=0;}
   else if(s->tail==(s->n-1))
    {s->a[0]=k;
     s->tail=0;}
   else 
    {s->a[++s->tail]=k;}
  }
  else
   printf("-1\n"); 
  }
  
  long int dequeue(struct queue *s)
  {long int v;
   if(qe(*s)==-1)
    return (-1);
   else
    {if(s->head==s->tail)
     {v=s->head;
      s->head=s->tail=-1;
      return s->a[v];} 
     else if(s->head==(s->n-1))
     {s->head=0;
      return s->a[(s->n-1)];}
     else
     {return (s->a[s->head++]);}
    }
  }
  
  void main()
  { struct queue s;
    long int a;
  s.head=s.tail=-1;
  char c;
  scanf("%ld",&s.n);
  
  do
  {scanf("%c",&c);
  switch(c)
  {case 'i':scanf("%ld",&a);
            enqueue(&s,a);
   break;
   case 'd':a=dequeue(&s);
            printf("%ld \n",a);
   break;
   case 'e':a=qe(s);
            printf("%ld \n",a);
   break;
   case 'f':a=qf(s);
            printf("%ld \n",a);
   break;}
   }while(c!='t');
   }
   
