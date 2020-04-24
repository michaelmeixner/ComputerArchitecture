#include "safeAdd.h"

bool safelyAdd(unsigned int a, unsigned int b, unsigned int *sid)
{
    char carry = 0; 

    asm(
        "movl %2, %%r8d\n\t"
        "addl %3, %%r8d\n\t"
        "setc %0\n\t"
        "movl %%r8d, (%1)\n\t"
        :"=r"(carry), "=r"(sid)
        :"r"(a), "r"(b)
        :"%r8"
    );

    return carry;
}