#include <stdio.h>
#include <math.h>

long power2(int base, int powerOfTwo)
{
    int result = base;
    int i = 0;
    while(i < powerOfTwo - 1)
    {
        result = result * base;
        i++;
    }
    return result;
}

long power(int base, int exponent)
{
    int result = 0;
    int i = 0;
    asm( //I couldn't test this part because I was getting a compile error, so I couldn't get it working, but I think the logic is correct
        "movl %1, %%rcx\n" //move base to %rcx
        "movl %2, %%rdx\n" //move exponent to %rdx
        "movl %%rcx, %0\n" //set base to result
        "movl $0, %3\n" //set i = 0
        "movl %3, %%rsi\n"
        "top:\n\t" //top:
        "compl %%rsi, -1(%%rdx)\n" //compare i to (exponent - 1)
        "jge end\n"
        "imull %0, %%rcx\n"
        "jmp top"
        "end:\n\t"
        :"=r"(result)
        :"r1"(base), "r2"(exponent), "r3"(i)
        :"%rcx", "%rdx", "%rsi"
    );

    return result;
}

int main()
{
    printf("%ld\n", power2(1, 2));
    printf("%ld\n", power2(2, 4));
    printf("%ld\n", power2(3, 8));
    printf("%ld\n", power2(8, 2));
}