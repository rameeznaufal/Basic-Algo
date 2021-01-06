#include <stdio.h>

//int count=0;

struct heap{int a[100000];
            int n;};

void swap(int a[],int c,int b)
{int temp;
 temp=a[c];
 a[c]=a[b];
 a[b]=temp;}
 
void max_heapify(struct heap *b,int i)
{int l,r,max;
 max=i;
 l=2*i+1;
 r=2*i+2;
 if((l<b->n)&&(b->a[l]>b->a[max]))
  max=l;
 if((r<b->n)&&(b->a[r]>b->a[max]))
  max=r;
 
//if(l<b->n&&r<b->n)
//   count+=2;
// else if(l<b->n)
//   count++;
   
 if(max!=i)
   {swap(b->a,i,max);
    max_heapify(b,max);}
}

void build_mheap(struct heap *a)
{for(int i=(a->n/2)-1;i>=0;--i)
   {max_heapify(a,i);}
}
 
void heapsort(struct heap *a)
{build_mheap(a);
 for(int i=a->n-1;i>=0 ;--i) 
  {swap(a->a,i,0);
   --a->n;
   max_heapify(a,0);
  } 
}

void main()
{struct heap a1;
 scanf("%d",&a1.n);
 int t=a1.n;
 for(int i=0;i<t;++i)
  scanf("%d",&a1.a[i]);
 heapsort(&a1);
 a1.n=t;
 for(int i=0;i<t;++i)
  printf("%d ",a1.a[i]); 
// printf("\n%d",count);
 }  
