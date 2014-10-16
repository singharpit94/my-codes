using namespace std;
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<limits>
#include<cmath>
#include<map>
#define LLU  long int
#define LLD long long double

void m34( long int arr[],  long int l,  long int m,  long int r)
{
     long int i, j, k;
     long int n1 = m - l + 1;
     long int n2 =  r - m;

    /* create temp arrays */
     long int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort( long int arr[],  long int l,  long int r)
{
    if (l < r)
    {
        long int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        m34(arr, l, m, r);
    }
}

int main()
{
    LLU t,j,n,k,a[1005],sum,i,vtr,s=1,flag;
    cin>>t;
    while(t--)
    {        sum=0,vtr=0,flag=0;
            cin>>n>>k;
            for(i=0;i<k;i++)
            cin>>a[i];
            mergeSort(a,0,k-1);
            //for(i=0;i<k;i++)
            //cout<<a[i]<<" ";
            j=k-1;
            while(j>=0)
            {
                   sum=sum+a[j];
                   vtr++;
                   j--;
                   if(sum>=n)
                {    flag=1;
                     break;
                   }

            }
            if(flag)
            {
                 cout<<"Scenario #"<<s<<":\n";
                 cout<<vtr<<"\n";
                 cout<<"\n";
            }
            else
            {
                 cout<<"Scenario #"<<s<<":\n";
                 cout<<"impossible"<<"\n";
                 cout<<"\n";

            }
            s++;


    }
    return 0;
}
