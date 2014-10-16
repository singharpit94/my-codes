#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
   long long int t,a[100100],b[100100],i,j,k,n,flag;

   while(1)
   {  flag=0;
      scanf("%lld",&n);
     if(n==0)
     break;
     for(i=1;i<=n;i++)
     {
            scanf("%lld",&a[i]);
            b[a[i]]=i;
     }
     for(i=1;i<=n;i++)
     {
          if(a[i]!=b[i])
          {
             flag=1;
             break;
          }
     }
     if(flag==0)
     printf("ambiguous\n");
     else
     printf("not ambiguous\n");



   }
   return 0;

}
