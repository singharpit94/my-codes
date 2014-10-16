#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <list>
#include <algorithm>
inline void inp( int &n )//fast input function
{
n=0;
int ch=getchar();
int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
n=n*sign;
}
inline void inp( long long int &n )//fast input function
{
n=0;
int ch=getchar();
int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
n=n*sign;
}

using namespace std;

#define lli long long int
#define li long int
struct s
{ lli x; lli y;lli d; };
struct sless
{ inline bool operator() (const s& s1, const s& s2) { return s1.d<s2.d; } };
int main()
{
            lli t,n,sx,sy,cx,cy,i,sum,di,a,b,c,d;
            inp(t);
            while(t--)
            {          sum=0;
                      inp(n);
                      vector <s> v;
                      s st;
                      for(i=0;i<n;i++)
                      {
                              inp(st.x);
                              inp(st.y);
                              st.d=0;
                              v.push_back(st);
                      }
                      inp(sx);
                      inp(sy);
                      inp(cx);
                      inp(cy);
                      vector<s>::iterator vi=v.begin();
                      for(;vi!=v.end();vi++)
                      {
                                di=((((*vi).x)-sx)*(((*vi).x)-sx)+(((*vi).y)-sy)*(((*vi).y)-sy));
                                ((*vi).d)=di;
                                //cout<<((*vi).d)<<"\n";
                      }
                      sort(v.begin(),v.end(),sless());
                      //for(vi=v.begin();vi!=v.end();vi++)
                      //cout<<((*vi).d)<<"\n";
                      vector<s>::iterator pi=v.begin();
                      sum=(sx-((*pi).x))*(sx-((*pi).x))+(sy-((*pi).y))*(sy-((*pi).y));
                      pi++;
                      //cout<<sum<<"\n";
                      for(;pi!=v.end();pi++)
                      {
                                a=((*pi).x);
                                b=((*pi).y);
                                c=((*(pi-1)).x);
                                d=((*(pi-1)).y);
                                cout<<a<<c<<b<<d;
                                sum+=((c-a)*(c-a))+((d-b)*(d-b));
                                cout<<sum<<"\n";


                      }

                      pi=v.end()-1;
                      sum+=(cx-((*pi).x))*(cx-((*pi).x))+(cx-((*pi).y))*(cx-((*pi).y));
                      cout<<sum<<"\n";



            }
}
