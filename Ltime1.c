#include<stdio.h>
#include<string.h>
void m34(long  long int arr[], long  long int l, long  long int m, long  long int r)
{
     long long int i, j, k;
     long long int n1 = m - l + 1;
    long  long int n2 =  r - m;

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
void mergeSort( long long int arr[], long  long int l,  long long int r)
{
    if (l < r)
    {
        long long int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        m34(arr, l, m, r);
    }
}
int main()
{
       long long int t,n,i,j,k,a[100100],sum;
       scanf("%lld",&t);
       while(t--)
       {      sum=0;
             scanf("%lld",&n);
             for(i=0;i<n;i++)
             scanf("%lld",&a[i]);
             mergeSort(a,0,n-1);
             if(n%2==0)
             {
                 for(i=n-1;i>=1;i=i-2)
                 sum+=a[i];
                 printf("%lld\n",sum);
             }
             else
             {
               for(i=n-1;i>=0;i=i-2)
               sum+=a[i];
               printf("%lld\n",sum);
             }


       }
       return 0;
}

