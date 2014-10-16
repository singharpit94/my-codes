#include<stdio.h>
int main()
{
             long  long int t,n,m,a[100100],i,j,k,sum,pos,flag,ctr;
            char b[100100];

            char ch;
            scanf("%lld",&t);
            while(t--)
            {
            for(i=1;i<=100100;i++)
            {a[i]=0,b[i]='\0';}
            sum=1,flag=0;
                       scanf("%lld %lld",&n,&m);
                       for(i=1;i<=m;i++)
                       {          scanf(" %c",&ch);
                                   b[i]=ch;
                                 scanf("%lld",&k);






                                 a[k]=ch;
                       }
                      // for(i=1;i<=n;i++)
                       //{
                         // if()

                       //}
                       /*for(i=1;i<m;i++)
                       {
                            if(b[i]!=b[i+1])
                            {flag=1;
                            break;}

                       }
                       if(m==1||flag==0)
                       printf("%lld\n",1);*/
                       pos=0,ctr=0;
                       for(i=1;i<=n;i++)

                       {

                            if(a[i]!=0&&(a[pos]!=a[i]))
                            {


                              sum=sum*((ctr+1)%1000000009);
                              sum=sum%1000000009;
                              ctr=0;
                              pos=i;
                            }
                            else if(a[pos]==a[i])
                            {
                                  pos=i;
                                  ctr=0;
                            }
                            else if(pos!=0)
                            {
                                ctr++;
                                ctr=ctr%1000000009;
                            }
                       }
                       sum=sum%1000000009;
                       printf("%lld\n",sum);





            }
            return 0;

}
