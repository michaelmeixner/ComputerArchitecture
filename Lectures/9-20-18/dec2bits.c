#include <stdio.h>
#include <math.h>

void main()
{
   // This program reads in a value between 0 and 255
   // and outputs it in binary.

   int value, i, powerOfTwo, nextBit, rest;

   printf("Please input a value between 0 and 255: ");
   scanf("%d", &value);
   printf("\n");

   powerOfTwo = 128; // 2 to the 7th power
   rest = value;

   for (i = 7; i >= 1; i--)
   {
      nextBit = rest / powerOfTwo; // determine next bit     
      printf("%d",nextBit);
      rest = rest - nextBit*powerOfTwo; // strip next bit off
      powerOfTwo = powerOfTwo / 2; // get ready to move to next bit
   }

   printf("%d", rest); // last bit

   int mask = 1 << 7;
   for(i = 0; i < 8; i++)
   {
       printf("%d", (((value & mask) == 0)? 0 : 1));
       mask >>= 1;
   }

   printf(" is the binary equivalent of %d\n", value);
}