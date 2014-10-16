#include<stdio.h>
#include<algorithm>
using namespace std;

struct data
{
    int x,y,z;
};
struct data a[400007];
int b[100005];

void update(int,int,int,int,int,int);
void change(int ss,int se,int i,int r,int s);
int cal(int ss,int se,int i,int r);
int main()
{
    int i;
    for(i=0;i<=400005;i++)
    {
        a[i].x=0;
        a[i].y=0;
        a[i].z=0;
    }
    int n,m;
    scanf("%d",&n);
    int q,r,s,t;
    for(i=0;i<n;i++)
    scanf("%d",&b[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&q);
        if(q==1)
        {
            scanf("%d%d%d",&r,&s,&t);
            r--;
            s--;
            update(0,n-1,r,s,0,t);
        }
        else
        {
            scanf("%d%d",&r,&s);
            r--;
            b[r]=s;
            change(0,n-1,0,r,s);
        }
    }
    //for(i=0;i<=6;i++)
    //printf("%d %d\n",a[i].x,a[i].y);
    for(i=0;i<n;i++)
    {
        q=0;
        q=cal(0,n-1,0,i);
        printf("%d ",q);
    }
    printf("\n");
    return 0;
}
int cal(int ss,int se,int i,int r)
{
    if(ss!=se)
    {
        int mid=(ss+se)/2;
        int q1;
        if(ss!=se)
        {
            a[2*i+1].x+=a[i].x;
            a[2*i+1].y+=a[i].y;
            a[2*i+1].z+=a[i].z;
            a[2*i+2].x+=a[i].x;
            a[2*i+2].y+=a[i].y;
            a[2*i+2].z+=a[i].z;
        }
        a[i].x=0;
        a[i].y=0;
        a[i].z=0;
        if(r<=mid)
        {
            q1=cal(ss,mid,2*i+1,r);
        }
        else
        {
            q1=cal(mid+1,se,2*i+2,r);
        }
        return q1;
    }
    else
    {
        while((a[i].x>0)&&(b[r]%2==0))
        {
            b[r]/=2;
            a[i].x--;
        }
        while((a[i].y>0)&&(b[r]%3==0))
        {
            b[r]/=3;
            a[i].y--;
        }
        while((a[i].z>0)&&(b[r]%5==0))
        {
            b[r]/=5;
            a[i].z--;
        }
        return b[r];
    }
}
void change(int ss,int se,int i,int r,int s)
{
    if(se<ss)
    return;
    if((r>=ss)&&(r<=se))
    {
        if(ss!=se)
        {
            a[2*i+1].x+=a[i].x;
            a[2*i+1].y+=a[i].y;
            a[2*i+1].z+=a[i].z;
            a[2*i+2].x+=a[i].x;
            a[2*i+2].y+=a[i].y;
            a[2*i+2].z+=a[i].z;
        }
        a[i].x=0;
        a[i].y=0;
        a[i].z=0;
    }
    if(ss!=se)
    {
        int mid=(ss+se)/2;
        if(r<=mid)
        {
            change(ss,mid,2*i+1,r,s);
        }
        else
        {
            change(mid+1,se,2*i+2,r,s);
        }
    }
}
void update(int ss,int se,int qs,int qe,int i,int t)
{
    if((qs>se)||(qe<ss))
    return;

    if((ss>=qs)&&(se<=qe))
    {
        //printf("ss=%d se=%d i=%d\n",ss,se,i);
        if(t==2)
        a[i].x++;
        else if(t==3)
        a[i].y++;
        else
        a[i].z++;
        return;
    }
    if(ss!=se)
    {
        int mid=(ss+se)/2;
        update(ss,mid,qs,qe,2*i+1,t);
        update(mid+1,se,qs,qe,2*i+2,t);
    }
}
 
