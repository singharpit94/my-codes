#include<stdio.h>
#include<stdlib.h>
int main()

{
      long int t,n,a[100100],i,ctr1,ctr2,ctr3;
      scanf("%ld",&t);
      while(t--)
      {          ctr1=0,ctr2=0,ctr3=0;
                scanf("%ld",&n);
                for(i=0;i<n;i++)
                {
                   scanf("%ld",&a[i]);
                   if(a[i]==1)
                   ctr1++;
                   else if(a[i]==2)
                   ctr2++;
                   else if(a[i]==3)
                   ctr3++;
                }

                if(ctr1>0&&ctr2==0&&ctr3==0)
                printf("%ld\n",0);
                else if(ctr1==0&&ctr2>0&&ctr3==0)
                printf("%ld\n",1);
                else if(ctr1==0&&ctr2==0&&ctr3>0)
                printf("%ld\n",1);
                else if(ctr1>0&&ctr2>0&&ctr3==0)
                printf("%ld\n",1);
                else if(ctr1>0&&ctr3>0&&ctr2==0)
                printf("%ld\n",1);
                else
                printf("%ld\n",2);

      }
      return 0;
}
