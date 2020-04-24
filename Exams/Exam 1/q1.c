#include <stdio.h>
#include <limits.h>

int mystery(int);
int mysteryC(int);

int main() 
{
    int count = 0;
    int count2 = 0;
    const int NUM = 100;
    for(int i = 1; i < NUM; i++) 
    {
        if(mystery(i))
        {
            count++;
        }
        if(mysteryC(i))
        {
            count2++;
        }
    }
    printf("In the range 1 to %d, %d numbers meet your criterion\n", NUM, count);
    printf("In the range 1 to %d, %d numbers meet your criterion\n", NUM, count2);
}

int mysteryC(int value)
{
    int result = 0;

    while(value > 0)
    {
        value = value / 2;
        result++;
    }
    result--;
    return !result;
}

int mystery(int value) 
{
    int result = 0;
    asm (
        "movl %1, %%r8d\n\t" //move value  to %r8d
        "movl $0, %%r9d\n\t" //move result to %r9d
        "top:\n\t" //top:
        "cmpl $0, %%r8d\n\t" //compare value to 0
        "jle end\n\t" //jump to end if value is less than or equal to 0
        "shr $1, %%r8d\n\t" //shift value right by L^1, where L is data type size in bits (4 in this case)
        "jnc top\n\t" //jump to top if result doesn't fit in assigned register
        "inc %%r9d\n\t" //increment result
        "jmp top\n\t" //jump to top
        "end:\n\t" //end:
        "dec %%r9d\n\t" //decrement result
        "movl %%r9d, %0\n\t" //move result to result
        :"=r"(result)
        :"r"(value)
        :"%r8", "%r9"
    );
    return !result;
}