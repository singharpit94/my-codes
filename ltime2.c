#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
        long int t,n,i,j=0,k,sum,ctr,ans,ctr1;
        long int *a=( long int*)calloc(sizeof( long int),1000);
        long int *c=( long int*)calloc(sizeof( long int),1000);
         long int b[15];

for(i=2;i<10;i++)
{
if(!a[i])
for(j=i;i*j<10;j++)
a[i*j]=1;
}


for(i=2;i<10;i++)

{
if(a[i]==0)
{c[j]=i;
j++;
}

}
//for(i=0;i<j;i++)
//printf("%ld",c[i]);


       scanf("%ld",&t);
       while(t--)
       {      ctr=0,sum=1,ans=0;
              scanf("%ld",&n);
              for(i=0;i<n;i++)
              scanf("%ld",&b[i]);
              k=0;
              while(k<j)

              {    if(c[k]!=0)
              {
                    ans++,sum=1,ctr1=0;
                   for(i=0;i<n;i++)

                   {
                         if(b[i]%c[k]==0||b[i]==1)
                         {
                              sum++;


                         }
                         if(b[i]!=1&&b[i]%c[k]==0)
                         {
                            ctr=1;
                            b[i]/=c[k];
                         }


                   }
                   if(ctr==0)
                         {
                             k++;
                         }
                    else

                    {
                          for(i=0;i<n;i++)
                          {
                              if(b[i]==1)
                              ctr1++;

                          }

                    }
                    if(ctr1==n)
                    break;
                }
                else
                k++;









              }
              printf("%ld\n",ans);

       }
       return 0;

}
