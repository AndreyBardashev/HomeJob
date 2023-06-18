#include <stdio.h>

void print_new (int f)
   {
       unsigned char c;
       for (int i = 0; i<4; i++)
          {
             c=((f>>8*i) & 0xFF);
             printf ("%x byte f=%x\n",i,c);
          }
   }

int main ()
   {

       int a = 0xDDCCBBAA;
       print_new(a);
       int b = 0x00CC0000;
       int d = a^b;
       print_new(d);
       return 0;
}
