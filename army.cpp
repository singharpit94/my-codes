
using namespace ::std;
#include<iostream>

#include<math.h>
int main()
{
         unsigned long long int n;
         cin>>n;
         if(n==1||n==0)
         cout<<"TAK";
         else if((n&(n-1))==0)
         cout<<"TAK"<<"\n";
         else
         cout<<"NIE"<<"\n";
         return 0;


}
