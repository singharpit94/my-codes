#include<stdio.h>
#include<stdlib.h>
int main()
{
     int t,n,i,j,perm,**pathx,**pathy;
    char s[1003][1003];
    long long int count1;
    scanf("%d",&t);
    pathx=(int**)malloc(1005*sizeof(int*));
    for(i=0;i<1005;i++)
        pathx[i]=(int*)malloc(1005*sizeof(int));
    pathy=(int**)malloc(1005*sizeof(int*));
    for(i=0;i<1005;i++)
        pathy[i]=(int*)malloc(1005*sizeof(int));
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                pathx[i][j]=0;
                pathy[i][j]=0;
            }
        }
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        for(j=0;j<n;j++)
        {

            for(i=n-1;i>=0;i--)
            {
                if(s[i][j]=='#')
                    break;
                else if(s[i][j]=='.')
                    pathy[i][j]=1;
            }
        }
        for(i=0;i<n;i++)
        {
            perm=1;
            for(j=n-1;j>=0;j--)
            {
                if(s[i][j]=='#')
                    break;
                else if(s[i][j]=='.')
                    pathx[i][j]=1;

            }
        }
        count1=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                if((pathx[i][j]==1) && (pathy[i][j]==1))
                    count1++;

        }
        printf("%lld\n",count1);

    }
    return 0;
}
