#include<stdio.h>
int main()
{
      unsigned  long int n;
      scanf("%lu",&n);
      if(n%10!=0)
      {
          printf("1\n");
          printf("%ld",n%10);

      }
      else
      printf("2\n");
      return 0;
}
