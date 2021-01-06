#include <stdio.h>

long int binary(int a[],long int l,long int n,int x)
{long int m;
 m=l+(n-l)/2;
 if(l<=n)
  {if(a[m]==x)
    {if(a[m-1]==x)
      return(binary(a,l,m-1,x));
     else 
      return(m);}
   else if(a[m]>x)
    return(binary(a,l,m-1,x));
   else
    return(binary(a,m+1,n,x));
  }
 return(-1);
}

void main()
{int x,a[10000],b[1000000];
 long int n,i,occ,q;   
 scanf("%ld",&n);
 scanf("%ld",&q);
 for(i=0;i<n;++i)
  {scanf("%d",&a[i]);}
 for(i=0;i<q;++i)
  {scanf("%d",&b[i]);}
  for(i=0;i<q;++i)
  {printf("%ld \n",binary(a,0,n-1,b[i]));}

}     
 
