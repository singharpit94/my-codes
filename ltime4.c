#include<stdio.h>
#include<stdlib.h>
int main()

{
      long int t,n,a[100100],b[100100],m,l,r,p,i,d,ch,x,j;
      scanf("%ld",&t);
      while(t--)
      {

      scanf("%ld",&n);
      for(i=1;i<=n;i++)
      scanf("%ld",&a[i]);
      scanf("%ld",&m);
      while(m--)
      {
           scanf("%ld",&ch)
           if(ch==2)
           {
                scanf("%ld %ld ",&l,&r);
                for(i=l,j=1;i<=r;i++)
                {
                    b[j]=a[i];
                    j++;
                }
                for(i=1;i<=n;i++)
                {
                   if(i<l||i>r)
                   {
                   b[j]=a[i];
                   j++;
                   }
                }
                for(i=1;i<j;i++)
                a[i]=b[i];


           }
           else
           {      x=1;
                 scanf("%ld %ld",&l,&r);

                 for(i=l+1;i<=r;i++)
                 {
                  if(a[i]!=a[i-1])
                  x++;
                 }
                 printf("%ld\n",x);
           }

      }
      }
      return 0;
    }
