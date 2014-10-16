#include<stdio.h>
#include<stdlib.h>
int main()

{
      long int t,n,a[100100],m,l,r,p,i,d,ch;
      scanf("%ld",&n);
      for(i=1;i<=n;i++)
      scanf("%ld",&a[i]);
      scanf("%ld",&m);
      while(m--)
      {
           scanf("%ld",&ch);
           if(ch==1)
           {
                scanf("%ld %ld %ld",&r,&l,&p);
                for(i=r;i<=l;i++)
                {
                    if(a[i]%p==0)
                    a[i]=a[i]/p;
                }

           }
           else
           {
                 scanf("%ld %ld",&l,&d);
                 a[l]=d;
           }
      }
      for(i=1;i<=n;i++)
      printf("%ld ",a[i]);
      return 0;
    }
