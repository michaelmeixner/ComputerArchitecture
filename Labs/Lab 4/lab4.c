//CSCI-4200 Lab 4, Michael Meixner
//The results do not surprise me because the compiler converts the user's array syntax to pointer syntax.

#include <stdio.h>
#include <string.h>

int inner(int *a, int *b)
{
   int result = 0;

//    int *endptr = a;
//    int *endptr2 = b;

//    while(*endptr != 999)
//    {
//        result += *endptr * *endptr2;
//        endptr += 1;
//        endptr2 += 1;
//    }

   for(int i = 0; *(a + i) != 999; i++)
   {
       result += *(a + i) * *(b + i);
   }

//   int i;

//    for (i = 0; a[i] != 999; i++)
//    {
//       result += a[i]*b[i];
//    }

   return result;
}

int main()
{
   int i, a[100], b[100];

   for (i = 0; i < 9; i++)
   {
      a[i] = i+1;
      b[i] = 9-i;
      printf("a[%d] = %d   b[%d] = %d\n",i,a[i],i,b[i]);
   }
      
   a[9] = b[9] = 999; // sentinels

   printf("\n");

   printf("Inner product is %d\n",inner(a,b));
}
