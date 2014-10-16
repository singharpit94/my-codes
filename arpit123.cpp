#include<iostream>
using namespace::std;

void fun(long long int,long long int,long long int);
int a[21][21];


static long long int num;
int main()
{          long long int n,k,ans,i,j;
           cin>>n;

           while(n--)
           {      num=0;
                 for(i=0;i<21;i++)
                 {
                     for(j=0;j<21;j++)
                     a[i][j]=0;
                 }
                 cin>>k;

                fun(k,1,1);
                 cout<<num;
           }
           return 0;
}
void  fun(long long int fi,long long int cu,long long int pos)
{                long long int i,j;
                 if(cu==fi&&pos!=cu)
                  {
                      num++;

                  }

                  else
            {
                 for(i=1,j=1;i<=fi;i++,j++)
                 {   if(cu>fi)
                      break;

                     if(i!=pos&&i!=cu&&a[j][i]!=1)
                     {   a[j][i]=1;
                         fun(fi,cu+1,i);
                      }
                 }

         }

}
