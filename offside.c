#include<stdio.h>
#include<stdlib.h>
void m34( long int arr[],   long int l,  long int m,   long int r)
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
void mergeSort(  long int arr[],   long int l,   long int r)
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
       long int a,d,at[15],df[15],i,j,ctr,ctr2,ans,se;
       while(1)
       {    ctr=1,ctr2=1,ans=0;
           scanf("%ld %ld",&a,&d);
           if(a==0&&d==0)
           break;
           for(i=1;i<=a;i++)
           scanf("%ld",&at[i]);
           for(i=1;i<=d;i++)
           scanf("%ld",&df[i]);
           mergeSort(at,1,a);
           mergeSort(df,1,d);
           //for(i=1;i<=d;i++)
           //printf("%ld ",df[i]);
           //for(i=1;i<=a;i++)
           //printf("%ld ",at[i]);
           for(i=1;i<d;i++)
           {
               if(df[i]==df[i+1])
               ctr++;
               else
               break;

           }
           for(i=ctr+1;i<d;i++)
           {
               if(df[i]==df[i+1])
               ctr2++;
               else
               break;
           }
           se=df[ctr+1];
           for(i=1;i<=a;i++)
           {
                if(at[i]<se||at[i]<df[1])
                {
                       if(at[i]==df[1]&&ctr<2)
                       ans++;
                }
           }
           if(ans>0)
           printf("Y\n");
           else
           printf("N\n");


       }
       return 0;
}
