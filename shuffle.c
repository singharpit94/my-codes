#include<stdio.h>
void find(long long int,long long int,long long int);


static long long int num;
int main()
{          long long int n,k,ans;
           scanf("%lld",&n);

           while(n--)
           {      num=0;

                 printf("arpit");
                find(k,1,1);
                 printf("%lld\n",num);
           }
           return 0;
}
void  find(long long int fi,long long int cu,long long int pos)
{                long long int i;
                 if(cu==fi&&pos!=cu)
                  {
                      num++;

                  }

                  else
            {
                 for(i=1;i<=fi;i++)
                 {
                     if(i!=pos&&i!=cu)
                     find(fi,cu+1,i);
                 }

         }

}
