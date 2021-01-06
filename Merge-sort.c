#include <stdio.h>
int Merge(int a[],int p,int q,int r)
{int b[(r-p)+1],i=p,j=q+1,k=0,flag=0;
 static int count;
 while(i<=q&&j<=r)
 {if(a[i]<a[j])
   {b[k]=a[i];
   if(flag&&(flag<a[i]))
     count++;
    k++;
    i++;
    }
  else
   {b[k]=a[j];
    flag=b[k];
    k++;
    j++;
    }
 }   
 while(i<=q)
 {b[k]=a[i];
   if(flag&&(flag<a[i]))
     count++; 
    k++;
    i++;
  }
 while(j<=r)
 {b[k]=a[j];
    k++;
    j++;
     }
 for(k=p,i=0;k<=r;++k,++i)
 {a[k]=b[i];}  
 
 return count; 
}

int MergeSort(int a[],int p,int r) 
{int m,ct;
 if(p<r)
 {m=p+(r-p)/2;
  MergeSort(a,p,m);
  MergeSort(a,m+1,r);
 ct=Merge(a,p,m,r);}
return ct;}

void Print(int a[],int n)
{for(int i=0;i<n;i++)
 {printf("%d ",a[i]);}
}

void main()
{int a[100000],n,v;
 scanf("%d",&n);
 for(int i=0;i<n;i++)
  {scanf("%d",&a[i]);}   
 v=MergeSort(a,0,n-1);
 Print(a,n);
 printf("\n%d",v);
} 
