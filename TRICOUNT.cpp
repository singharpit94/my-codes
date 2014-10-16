using namespace std;
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<limits>
#include<cmath>
#include<map>
#define LLU long long unsigned int
#define LLD long long double
#define FOR(i,N) for(int i=0;i<(N);i++)
int main()
{
      LLU t,i,n;
      cin>>t;
      while(t--)
      {
           cin>>n;
           i=n*n +(n-1)*(n-1);
           cout<<i<<"\n";

      }
      return 0;
}
