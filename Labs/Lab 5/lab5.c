#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b, int c)
{
    int largest = 0;

    asm(
        "cmpl %1, %2\n"     //compare a to b
        "jl .L2\n"          //jump to L2 if a is greater than b
        "jmp .L3\n"          //jump to L3 if a is less than b

        ".L2:\n"            //L2
        "cmpl %1, %3\n"     //compare a to c
        "jl .L4\n"          //jump to L4 if a is greater than c
        "jmp .L5\n"          //jump to L5 if a is less than c

        ".L3:\n"            //L3
        "cmpl %2, %3\n"     //compare b to c
        "jl .L6\n"          //jump to L6 if b is greater than c
        "jmp .L5\n"          //jump to L5 if b is less than c

        ".L4:\n"            //L4
        "movl %1, %0\n"     //move a into result
        "jmp end\n"

        ".L5:\n"            //L5
        "movl %3, %0\n"     //move c into result
        "jmp end\n"

        ".L6:\n"            //L6
        "movl %2, %0\n"     //move b into result
        "jmp end\n"

        "end:\n"

        :"=r"(largest)
        :"r"(a), "r"(b), "r"(c)
    );

    return largest;
}

int main()
{
    printf("%d\n", compare(1, 2, 3));
    printf("%d\n", compare(5, 4, 8));
    printf("%d\n", compare(9, 11, 5));
}