#include <stdio.h>
#define N 15
int a[N][N];

int main ()
{

   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) a[i][j]=i*N+j+1;
   for (int i = 0; i < N; i++)
      {
        for (int j = 0; j < N; j++) printf ("%d\t",a[i][j]);
        printf("\n");
      }   
   return 0;
}
