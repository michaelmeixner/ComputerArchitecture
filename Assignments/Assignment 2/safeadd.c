#include "safeadd.h"
#include <stdio.h>

bool safelyAddU(unsigned int a, unsigned int b, unsigned int *sid) {
    char carry = 0;

    asm(
        "movl %1, %%r8d\n\t"
        "addl %2, %%r8d\n\t"
        "setc %0\n\t"
        "movl %%r8d, (%3)\n\t"
        :"=r"(carry)
        :"r"(a), "r"(b), "r"(sid)
        :"%r8"
    );

    return carry;
}

bool safelyAddS(int a, int b, int *sid)
{
    char carry = 0;

    asm(
        "movb $0, %0\n\t"
        "movl %1, %%r8d\n\t"
        "addl %2, %%r8d\n\t"
        "sets %%r9b\n\t"
        "setl %%r10b\n\t"
        "cmpb %%r9b, %%r10b\n\t"
        "jnz overflow\n\t"
        "jmp end\n\t"
        "overflow:\n"
        "movb $1, %0\n\t"
        "end:\n\t"
        // "xor %%r9b, %%r10b\n\t"
        // "movb %%r10b, %0\n\t"
        "movl %%r8d, (%3)\n\t"
        :"=r"(carry)
        :"r"(a), "r"(b), "r"(sid)
        :"%r8", "%r9", "%r10"
    );
    printf("adding %d to %d gives overflow? %d\n", a, b, carry);
    return carry;
}