#include<stdio.h>
#include<math.h>
int main()
{
         int  g,b,ans;

         while(1)
         {
             scanf("%d %d",&g,&b);
             if(g==-1&&b==-1)
             break;
             if(g==0&&b==0)
             printf("0\n");
             else if(g==b||g==b-1||b==g-1)
             printf("1\n");
             else if(g==0&&b!=0)
             printf("%d\n",b);
             else if(b==0&&g!=0)
             printf("%d\n",g);

             else if(b>g)
             {
                 ans=b/(g+1);
                 if(b%(g+1)!=0)
                 printf("%d\n",ans+1);
                 else
                 printf("%d\n",ans);
             }
             else
             {
                ans=g/(b+1);
                if(g%(b+1)!=0)

                printf("%d\n",ans+1);
                else
                printf("%d\n",ans);
             }



         }
         return 0;
}
