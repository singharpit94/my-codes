#include<stdio.h>
int main()
{
    long long int n,a[10010],b[10010],max,i,j,sum1=0,sum2=0,min=0,w,l;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
               scanf("%lld",&a[i]);
               scanf("%lld",&b[i]);
               sum1+=a[i];
               sum2+=b[i];
               if(sum1>=sum2)
               {

                   l=sum1-sum2;
                   if(l>min)
                   {w=1;
                   min=l;
                   }
               }
               else
               {

                     l=sum2-sum1;
                     if(l>min)
                     {
                      min=l;
                      w=2;
                      }
               }

    }
                   printf("%lld %lld",w,min);
               return 0;

}
