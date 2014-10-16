#include<stdio.h>
#include<stdlib.h>
 long int binarySearch( long int arr[],  long int l,  long int r,  long int x)
{
  while (l <= r)
  {
    long  int m = l + (r-l)/2;

    if (arr[m] == x) return m;  // Check if x is present at mid

    if (arr[m] < x) l = m + 1; // If x greater, ignore left half

    else r = m - 1; // If x is smaller, ignore right half
  }
  return -1;
}// if we reach here, then element was not present
  void merge( long int arr[],  long int l,  long int m,  long int r)
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
        merge(arr, l, m, r);
    }
}


/* UITLITY FUNCTIONS */
/* Function to print an array */
void printArray( long int A[], long  int size)
{
    long int i;
    for (i=0; i < size; i++)
        printf("%ld ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */

long int n1,n2,n3,m=0,i,temp,ctr=0,l1,l2;


int main()
{

                          scanf("%ld %ld %ld",&n1,&n2,&n3);
                           long int *a,*b,*c,*d;
                          a=(long int*)malloc(sizeof( long int)*n1);
                          b=( long int*)malloc(sizeof(long int)*n2);
                          c=(long int*)malloc(sizeof(long int)*n3);
                          d=(long int*)malloc(sizeof(long int)*(n1+n2+n3));






             for(i=0;i<n1;i++)
             {
                scanf("%ld",&a[i]);

             }
             for(i=0;i<n2;i++)
             {
                  scanf("%ld",&b[i]);

             }
             for(i=0;i<n3;i++)
             {
                  scanf("%ld",&c[i]);


             }


             for(i=0;i<n1;i++)
             {
                 l1=binarySearch(b, 0, n2-1, a[i]);
                 l2=binarySearch(c, 0, n3-1, a[i]);
                 if(l1!=-1||l2!=-1)
                 {
                      d[m]=a[i];
                      m++;
                 }

             }
             //printArray(d,m);
             for(i=0;i<n2;i++)
             {
                 l1=binarySearch(a, 0, n1-1, b[i]);
                 l2=binarySearch(c, 0, n3-1, b[i]);
                 if(l1!=-1||l2!=-1)
                 {
                      d[m]=b[i];
                      m++;
                 }

             }
             //printArray(d,m);

             for(i=0;i<n3;i++)
             {
                 l1=binarySearch(a, 0, n1-1, c[i]);
                 l2=binarySearch(b, 0, n2-1, c[i]);
                 if(l1!=-1||l2!=-1)
                 {
                      d[m]=c[i];
                      m++;
                 }

             }
             //printArray(d,m);
             mergeSort(d, 0, m-1);
             //printArray(d,m);
             for(i=1;i<m;i++)
             {
                    if(d[i]!=d[i-1])
                    ctr++;
             }


             ctr++;
             printf("%ld\n",ctr);
             printf("%ld\n",d[0]);
             for(i=1;i<m;i++)
             {
                 if(d[i]!=d[i-1])
                 printf("%ld\n",d[i]);
             }
          return 0;


}
