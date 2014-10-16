#include<stdio.h>
int main()
{
       long long int t,n,g,i,q;
       scanf("%lld",&t);
       while(t--)
       {
              scanf("%lld",&g);
              while(g--)
              {
                  scanf("%lld %lld %lld",&i,&n,&q);
                  if(n%2==0)
                  printf("%lld\n",n/2);
                  else
                  {
                      if(i==1)
                      {
                           if(q==1)
                           printf("%lld\n",n/2);
                           else
                           printf("%lld\n",n/2+1);
                      }
                      else
                      {
                      if(q==1)
                      printf("%lld\n",n/2+1);
                      else
                      printf("%lld\n",n/2);
                        }
                  }
              }
       }
       return 0;
}
