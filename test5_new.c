#include <stdio.h>
#define N 15
int a[N][N];

int main ()
{
   int k = 1;
   for (int i = 0; i < N; i++)
      {
          for (int j = 0; j < N-k; j++) a[i][j]=0;
          for (int j = N-k; j < N; j++) a[i][j]=1;
          k++;
      }
   for (int i = 0; i < N; i++)
      {
        for (int j = 0; j < N; j++) printf ("%d\t",a[i][j]);
        printf("\n");
      }   
   return 0;
}
