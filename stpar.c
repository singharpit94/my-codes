#include<stdio.h>
int n,a[1005],b[1005],c[1005],i,j,k,sum;
void push( int, int);
 int  pop( int);
int main()
{

      while(1)
      {     j=1,k=0,sum=0;

           scanf("%d",&n);
           if(n==0)
           break;
           for(i=1;i<=n;i++)
           scanf("%d",&a[i]);
           for(i=1;i<=n;i++)
           {
                 if(a[i]==j)
                 {      b[j]=j;
                        j++;

                  }
                  else if(j==pop(k-1))
                  {   b[j]=j;
                      j++;
                      k--;
                  }
                 else
                 {   if(k>0)
                     {
                         if(c[k-1]<a[i])
                         sum=1;
                         break;
                     }
                     push(a[i],k);
                     k++;

                 }

           }
           if(j<=n&&sum==0)
           {
               while(k>0)
               {   b[j]=pop(k-1);
                   j++;
                   k--;
               }
           }


           if(sum==0)
      {           for(i=1;i<j-1;i++)
           {
                if(b[i]>b[i+1])
                {sum=1;
                  break;
                }
            }

      }     if(sum==0)
           puts("yes");
           else
           puts("no");

         }
         return 0;


}
void push( int item, int pos)
{
     c[pos]=item;

}
 int pop( int pos)
{      if(pos==-1)
        return -1;
        else
      return c[pos];
}
