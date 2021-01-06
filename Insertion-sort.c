#include <stdio.h>

//int count=0;

void InsertionSort(int a[],int n)
{int temp,i,j;
 for(i=1;i<n;++i)
 {temp=a[i];
  j=i-1;
  while(a[j]>temp&&j>=0)
   {a[j+1]=a[j];
    --j;
    //count++;
    }  
 // if(a[j]<=temp&&j>=0)
 //  count++;  
  a[j+1]=temp;}
  
}

void Print(int a[],int n)    
{for(int i=0;i<n;++i)
 {printf("%d ",a[i]);}
}

void main()
{int a[10000],x;
 scanf("%d",&x);
 for(int i=0;i<x;++i)
 {scanf("%d",&a[i]);}
 InsertionSort(a,x);
 Print(a,x);
 //printf("\n%d",count);
}
