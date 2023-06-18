#include <stdio.h>
#define N 4

int main ()
   {

       int a = 0xDDCCBBAA;
       char *ptr;
       ptr = &a;
       for (int i = 0; i<N; i++)
          {
             printf ("%d byte f=%x\n",i,*ptr&0xFF);
             ptr++;
          }
       ptr = &a;
       ptr = ptr+2;
       *ptr = 0;
       ptr = &a;
       for (int i = 0; i<N; i++)
          {
             printf ("%d byte f=%x\n",i,*ptr&0xFF);
             ptr++;
          }

       return 0;
}
