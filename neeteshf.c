#include<stdio.h>

void merge(long long int y[],char x[], long long int l, long long int m, long long int r)
{
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 =  r - m;


    long long int L[n1], R[n2];
    char L1[n1],R1[n2];

    for(i = 0; i < n1; i++)
    {
    	L[i] = y[l + i];
    	L1[i] = x[l + i];
    }

    for(j = 0; j < n2; j++)
    {
    	R[j] = y[m + 1+ j];
    	R1[j] = x[m + 1+ j];
    }


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            y[k] = L[i];
            x[k] = L1[i];
            i++;
        }
        else
        {
            y[k] = R[j];
            x[k] = R1[i];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        y[k] = L[i];
        x[k] = L1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        y[k] = R[j];
        x[k] = R1[j];
        j++;
        k++;
    }
}

void mergeSort(long long int y[],char x[],long long int l, long long int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(y,x, l, m);
        mergeSort(y,x, m+1, r);
        merge(y,x, l, m, r);
    }
}



int main()
{
	int t;
	long long int n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		long long int y[m],i,s=1;
		char x[m];
		for(i=0;i<m;i++)
		scanf(" %c%lld",&x[i],&y[i]);
	    mergeSort(y,x, 0, m-1);
	    //for(i=0;i<m;i++)
		//printf("%c%lld\n",x[i],y[i]);
		for(i=0;i<m-1;i++)
		   {
			if(x[i+1]!=x[i])
			{
				s=s*(y[i+1]-y[i])%1000000009;
			}
		   }
	    	printf("%lld\n",s);
	}
}
