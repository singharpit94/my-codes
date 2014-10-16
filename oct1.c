#include<stdio.h>
int main()
{
   long long int t,n,a[100100],i,j,k,m;
   scanf("%lld",&t);
   while(t--)
   {
       scanf("%lld %lld",&n,&m);
       k=m;
       for(i=1;i<=n;i++)
       {
           scanf("%lld",&a[i]);
           k+=a[i];
       }
       if(k%n==0)
       printf("Yes\n");
       else
       printf("No\n");
   }
   return 0;

}
