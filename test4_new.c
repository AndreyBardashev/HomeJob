#include <stdio.h>
#define N 15
int a[N];

int main ()
{

   for (int i = 0; i < N; i++) a[i]=i+1;
   for (int i = 0; i < N; i++) printf ("%d\t",a[i]);
   printf("\n");
   for (int i = N-1; i > -1; i--) printf ("%d\t",a[i]);
   printf("\n"); 
   return 0;
}
