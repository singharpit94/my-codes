#include<stdio.h>
#include<math.h>
#include<stdio.h>

int main()
{
          long long int t,n1,i,j,k,count,ctr,sum,m,n;

          scanf("%lld",&t);
          while(t--)
          {

             count =0;
             m=1,n=1;
             sum=0;
                 scanf("%lld",&n1);
                 long long int a[n1],b[n1],c[n1];
                 for(i=1;i<=n1;i++)
                 {
                     scanf("%lld",&a[i]);
                     if(a[i]<0)
                     {b[m]=i;
                     m++;
                    }
                     else
                     {c[n]=i;
                     n++;
                     }


                 }
                 //for(i=1;i<m;i++)
                 //printf("%lld %lld ",b[i],c[i]);
                 j=1,k=1;




                                  while(k<m&&j<n)
                                    {
                                     if(a[c[j]]>abs(a[b[k]]))
                                     {
                                          ctr=abs(a[b[k]]);
                                          a[b[k]]=0;

                                          a[c[j]]-=ctr;


                                          count+=ctr*abs(b[k]-c[j]);
                                          k++;

                                     }
                                     else
                                     {
                                         ctr=a[c[j]];
                                         a[c[j]]=0;

                                         a[b[k]]+=ctr;

                                         count+=ctr*abs(b[k]-c[j]);
                                         j++;

                                    }

                               }


                 printf("%lld\n",count);
          }
          return 0;
}
