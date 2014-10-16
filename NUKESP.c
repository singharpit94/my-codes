    #include<stdio.h>
    #include<stdlib.h>
    long long int K ,N;
    long long int a[101];
    long long int A;
    static long long int i=1;
    long long int j;
    void app();
    void fun(long long int);
    int main()
    {

    scanf("%lld %lld %lld",&A,&N,&K);


    for(j=1;j<=K;j++)
    a[j]=0;

    app();
    for(j=1;j<=K;j++)
    printf("%lld ",a[j]);
    printf("\n");












    return 0;
    }
    void app()
    {
    while(A>0)
    {
    a[i]=a[i]+1;
    if(a[i]>N)
    {
    a[i]=0;
    a[i+1]=a[i+1]+1;
    if(a[i+1]>N)
    fun(i+1);
    }
    A--;
    }


    }
    void fun(long long int f)
    {
    a[f]=0;
    if(f<K)


    a[f+1]=a[f+1]+1;
    if(a[f+1]>N)
    {
    fun(f+1);
    }

    }
