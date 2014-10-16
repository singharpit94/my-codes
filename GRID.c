#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{         int t,n,i,j,k;
          long int ctr;
          char a[1010][1010],d[1010];
          int **b,**c;
          b=(int**)malloc(sizeof(int*)*1005);
          for(i=0;i<1005;i++)
          b[i]=(int*)malloc(sizeof(int)*1005);
          c=(int**)malloc(sizeof(int*)*1005);
          for(i=0;i<1005;i++)
          c[i]=(int*)malloc(sizeof(int)*1005);

           scanf("%d",&t);
          while(t--)
          {   for(i=0;i<1005;i++)
          {
             for(j=0;j<1005;j++)
            {
                 b[i][j]=0;
                 c[i][j]=0;
             }
          }

               ctr=0;
               scanf("%d",&n);
               for(i=0;i<n;i++)
               {
                      scanf("%s",d);
                      for(j=0;j<n;j++)
                      a[i][j]=d[j];

               }

               for(i=0;i<n;i++)
               {
                   for(j=n-1;j>=0;j--)
                   {
                       if(a[i][j]=='#')
                       break;
                       else if(a[i][j]=='.')
                       {
                          b[i][j]=1;
                       }
                   }
               }
               /*for(i=0;i<n;i++)
               {   for(j=0;j<n;j++)
                    printf("%d",b[i][j]);
                    printf("\n");
               }*/
               for(i=0;i<n;i++)
               {
                    for(j=n-1;j>=0;j--)
                    {
                            if(a[j][i]=='#')
                            break;
                            else if(a[j][i]=='.')
                            c[j][i]=1;
                    }
               }
               /*for(i=0;i<n;i++)
               {   for(j=0;j<n;j++)
                    printf("%d",c[i][j]);
                    printf("\n");
               }*/
               for(i=0;i<n;i++)
               {        for(j=0;j<n;j++)
                       {
                            if(b[i][j]==1&&c[i][j]==1)
                            ctr++;
                       }
               }
               printf("%ld\n",ctr);


          }
          return 0;


}
