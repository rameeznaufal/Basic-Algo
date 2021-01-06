#include <stdio.h>

//int count=0;

int Partition(int a[],int p,int r)
{int x,i,j,t;
 x=a[r];
 i=p-1;
 for(j=p;j<=r-1;++j)
 {if(a[j]<=x)
   {i++;
    t=a[i];
    a[i]=a[j];
    a[j]=t;}
 //   count++;
 }
 t=a[i+1];
 a[i+1]=a[r];
 a[r]=t;
 return  (i+1);
}

void quicksort(int a[],int p,int r)
{int q;
 if(p<r)
 {q=Partition(a,p,r);
  quicksort(a,p,q-1);
  quicksort(a,q+1,r);}
}  

void print(int a[],int n)
{ for(int i=0;i<n;++i)
 {printf("%d ",a[i]);}
 }

void main()
{int a[100000],n;
 scanf("%d",&n);
 for(int i=0;i<n;++i)
 {scanf("%d",&a[i]);}
 quicksort(a,0,n-1);
 print(a,n);
// printf("\n%d",count);
}
 
