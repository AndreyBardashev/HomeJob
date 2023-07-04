#include <stdio.h>

int summation(int iA, int iB);

int subtracting(int iA, int iB);

int multiplication(int iA, int iB);

int division(int iA, int iB);

int main(void)
  {  
     int intA, intB, bool;
     while (1)
       { 
          printf ("Calculator version 0.000.00001/fixed\n");
          printf ("Please enter two integers 'A' and 'B'\n");
          scanf("%d%d", &intA, &intB);
          printf ("Make your choise - please press key from '1' to '5'\n");
          printf ("1. Summation of two integers 'A'+'B'\n2. Subtracting two integers 'A'-'B'\n3. Multiplication of two integers 'A'*'B'\n4. Division of two integers 'A'/'B'\n5. Exit\n");
          scanf("%d",&bool);
          switch(bool)
             {
               case 1:
                  summation(intA, intB);
                  break;
               case 2:
                  subtracting(intA, intB);
                  break;
               case 3:
                  multiplication(intA, intB);
                  break;
               case 4:
                  if (intB == 0) printf ("'B' cannot be equal zero\n"); 
                   else division(intA, intB);
                  break;
               case 5:
                  return 0;
               default:
                  break;
             }
        }
    return 0;
  }
  
int summation(int iA, int iB)
  {
    printf ("'A'+'B' = %d\n", iA+iB);
  }

int subtracting(int iA, int iB)
  {  
    printf ("'A'-'B' = %d\n", iA-iB);
  }

int multiplication(int iA, int iB)
  {  
    printf ("'A'*'B' = %d\n", iA*iB);
  }

int division(int iA, int iB)
  {
    printf ("'A'/'B' = %.3E\n", (float)iA/iB);
  }
