#include<stdio.h>
int main()
{
           long long int t,g,b1,m,r,i,j,k,a[105],b[105],c[105],max1,max2,max3,pos,max,in;
           scanf("%lld",&t);
           while(t--)
           {    max1=0;
           max2=0;
           max3=0;
               scanf("%lld %lld %lld %lld",&r,&g,&b1,&m);
               for(i=1;i<=r;i++)
               {
                    scanf("%lld",&a[i]);
                    if(a[i]>max1)
                    {
                       max1=a[i];

                       pos=1;
                       in=i;
                    }
               }
               for(i=1;i<=g;i++)
               {
                    scanf("%lld",&b[i]);
                    if(b[i]>max2)
                    {
                       max2=b[i];

                       pos=2;
                       in=3;
                    }
               }
               for(i=1;i<=b1;i++)
               {
                    scanf("%lld",&c[i]);
                    if(c[i]>max3)
                    {
                       max3=c[i];

                       pos=3;
                       in=3;
                    }
               }
               while(m--)
               {
                        if(max1>=max2)
                        {
                            if(max1>=max3)
                            max1=max1/2;
                            else
                            max3=max3/2;
                        }
                        else


                        {
                            if(max2>=max3)
                            max2=max2/2;
                            else
                            max3=max3/2;



                        }
            }
            if(max1>=max2)
                        {
                            if(max1>=max3)
                            max=max1;
                            else
                            max=max3;
                        }
                        else


                        {
                            if(max2>=max3)
                            max=max2;
                            else
                            max=max3;



                        }

               printf("%lld\n",max);

           }
           return 0;
}
