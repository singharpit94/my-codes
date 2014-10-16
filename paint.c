#include<stdio.h>
 long long int n,m,k,i,j,x,y,b[10005],c[10005],ctr=0,z=1;
  char a[101][101];
int main()
{

     scanf("%lld %lld %lld",&n,&m,&k);

     for(i=0;i<n;i++)
     {
        for(j=0;j<m;j++)
        a[i][j]='w';
     }
     for(i=1;i<=k;i++)
     {
        scanf("%lld %lld",&x,&y);
        a[x-1][y-1]='b';
     }
     for(j=0;j<m;j++)
     {
            for(i=0;i<n;)
            {
                if(a[i][j]=='w')
                {
                       ctr++;
                       b[z]=i+1;
                       c[z]=j+1;
                       z++;
                       while(a[i][j]!='b'&&i<n)
                       {
                          a[i][j]='r';
                          i++;
                       }
                }
                i++;
            }

     }
     printf("%lld\n",ctr);
     for(i=1;i<z;i++)
     printf("%lld %lld %s\n",b[i],c[i],"1");

     return 0;
}
