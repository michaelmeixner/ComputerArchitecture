#include <stdio.h>

long doSomething(int, int);
long doSomethingUnrolled(int, int);

int main()
{
    printf("Do Something: %ld\n", doSomething(100, 200));
    printf("Do Something Unrolled: %ld\n", doSomethingUnrolled(100, 200));

}

long doSomething(int a, int b)
{
    long result = 0;

    asm(
        "movq $0, %%rax\n\t"
        "start:\n\t"
        "cmpq %%rdi, %%rsi\n\t" // a is rdi and b is rsi
        "jl done\n\t" // jump to done if b is less than a
        "addq %%rdi, %%rax\n\t" // add a to result
        "inc %%rdi\n\t" // increment a
        "jmp start\n\t" // go back to start (loop)
        "done:\n\t"
        "movq %%rax, %0" // move result back into return value
        :"=r"(result)
        :
        :
    );

    return result;
}

long doSomethingUnrolled(int a, int b)
{
    long result = 0;

    asm(
        "movq $0, %%rax\n\t"
        "begin:\n\t"
        "inc %%rdi\n\t" // increment a
        "cmpq %%rdi, %%rsi\n\t" // a+1 is rdi and b is rsi
        "jl end\n\t" // jump to end if b is less than a+1
        "dec %%rdi\n\t" // decrement a
        "addq %%rdi, %%rax\n\t" // add a to result
        "inc %%rdi\n\t"
        "addq %%rdi, %%rax\n\t" // add a+1 to result
        "inc %%rdi\n\t" // increment a
        "jmp begin\n\t" // go back to begin (loop)
        "end:\n\t"
        "dec %%rdi\n\t" // decrement a
        "addq %%rdi, %%rax\n\t" // add a+1 to result
        "movq %%rax, %0" // move result back into return value
        :"=r"(result)
        :
        :
    );

    return result;
}
