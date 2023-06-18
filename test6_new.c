#include <stdio.h>
#define N 15
int a[N][N];

int main ()
{
   int i = 0, j, k = 0, p = 1;

   while (i < N*N)
     {
        k++;
        for (j = k-1; j < N-k+1; j++)
            {
               a[k-1][j]=p++;
               i++;
            }
        for (j = k; j < N-k+1; j++)
            {
               a[j][N-k]=p++;
               i++;
            }
        for (j = N-k-1; j >= k-1; j--)
            {
                a[N-k][j]=p++;
                i++;
            }
        for (j=N-k-1;j>=k;j--)
            {
                a[j][k-1]=p++;
                i++;
            }
      }

   for (int i = 0; i < N; i++)
      {
        for (int j = 0; j < N; j++) printf ("%d\t",a[i][j]);
        printf("\n");
      }   
   return 0;
}
