#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;
long long int p[1000005]={0};
long long int a[1000005]={0};
long long int z[1000005];
long long int b[100005];
int main()
{
    long long int t,i,p1,j,n,y,c,ans;
    for(i=2;i*i<=1000000;i++)
    {
        if(p[i]==0)
        {
            a[i]=1;
            for(j=i+i;j<=1000000;j+=i)
            p[j]=1;
        }
    }
    for(i=2;i<=1000000;i++)
    {
        if(p[i]==0)
        {
            a[i]=1;
        }
    }
    //printf("dsfs\n");
    scanf("%lld",&t);
    while(t--)
    {

        for(i=0;i<=1000000;i++)
        z[i]=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        scanf("%lld",&b[i]);

        for(i=0;i<n;i++)
        {
          //  printf("i=%lld\n",i);
            if(a[b[i]]==1)
            {
                ans=1;
                z[b[i]]=max(z[b[i]],ans);
            }
            else
            {
                y=b[i];
                for(j=2;j*j<=y;j++)
                {
                c=0;
                while((a[j]==1)&&(b[i]%j==0))
                {
                    c++;
                    b[i]/=j;
                }
                if(a[j]==1)
                {
                    z[j]=max(z[j],c);
                }

                }
                if(b[i]>1)
                {
                    ans=1;
                    z[b[i]]=max(z[b[i]],ans);
                }
                //printf("aa %lld\n",b[i]);

            }
        }
        ans=0;
        //printf("z2=%lld\n",z[2]);
        for(i=1;i<=1000000;i++)
        {
            //printf("adfsdf\n");
            ans+=z[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
 
