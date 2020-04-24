#include <stdio.h>
#include <limits.h>
#include "safeadd.h"

int main()
{
    unsigned int a = 1;
    unsigned int b = UINT_MAX - 5;
    unsigned int c = 0;

    for(int i = 0; i <= 5; i++)
    {
        bool overflow = safelyAddU(a, b + i, &c);    //add a and b and put the result in the address of c
        if(!overflow)
        {
            printf("Result = %u\n", c);
        }
        else
        {
            printf("Overflow!\n");
        }
    }

        int sc = 0;
    for(int i = 0; i <= 5; i++)
    {
        bool overflow = safelyAddS(a, (INT_MAX- 4) + i, &sc);    //add a and b and put the result in the address of c
        if(!overflow)
        {
            printf("Result = %d\n", sc);
        }
        else
        {
            printf("Overflow! Answer = %d\n", sc);
        }
    }
        printf("\nAdding %d to 1\n", INT_MAX);
        bool overflow = safelyAddS(INT_MAX, 1, &sc);    //add a and b and put the result in the address of c
        if(!overflow)
        {
            printf("Result = %d\n", sc);
        }
        else
        {
            printf("Overflow! Answer = %d\n", sc);
        }
        printf("\nAdding %d to -1\n", INT_MIN);
         overflow = safelyAddS(INT_MIN, -1, &sc);    //add a and b and put the result in the address of c
        if(!overflow)
        {
            printf("Result = %d\n", sc);
        }
        else
        {
            printf("Overflow! Answer = %d\n", sc);
        }
        printf("\nAdding %d to 1\n", 1);
         overflow = safelyAddS(1, 1, &sc);    //add a and b and put the result in the address of c
        if(!overflow)
        {
            printf("Result = %d\n", sc);
        }
        else
        {
            printf("Overflow! Answer = %d\n", sc);
        }
}