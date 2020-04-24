#include <stdio.h>
#include <time.h>

#define BUFFER_SIZE 50

void prettyFormatting(int *, char *, int);
void prettyFormattingFaster(int *, char *, int);

int main()
{
    int ugly[BUFFER_SIZE] = {0x54, 0x73, 0x61, 0x61, 0x69, 0x69, 0x6c, 0x71, 0x73, 0x6f, 0x20, 0x74, 0x27, 0x20, 0x76, 0x20, 0x21,0x68, 0x20, 0x73, 0x20, 0x66, 0x63, 0x74, 0x75, 0x74, 0x6e, 0x62, 0x20, 0x76, 0x73, 0x65, 0x69, 0x00,0x69, 0x77, 0x20, 0x64, 0x66, 0x75, 0x20, 0x65, 0x69, 0x2c, 0x75, 0x49, 0x65, 0x6f, 0x64, 0x74};
    char pretty[BUFFER_SIZE];
    char pretty2[BUFFER_SIZE];
    double start, end, result;

    start = time();
    prettyFormatting(ugly, pretty, BUFFER_SIZE);
    end = time();
    result = end - start;
    printf("time for normal = %f\n", result);

    start = time();
    prettyFormattingFaster(ugly, pretty2, BUFFER_SIZE);
    end = time();
    result = end - start;
    printf("time for unrolled = %f\n", result);

    //After coding it, verify that the pretty one really is pretty:
    //1) create another array and compare the data from the original method 
    //   to the data from the faster.
    //2) once verified, print the data from the faster one
}

void prettyFormatting(int *source, char *dest, int size)
{
    asm (
        "movq $0, %%r8\n\t" // move 0 into r8
        "movq $0, %%r9\n\t" // move 0 into r9
        "startI:\n\t"
        "cmpq $3, %%r9\n\t" // compare r9 to 3
        "jge endI\n\t" // jump to endI if r9 is greater than or equal to 3
        "movq %%r9, %%r10\n\t" // move r9 into r10
        // nested loop
        "startII:\n\t"
        "cmpl %2, %%r10d\n\t" // compare r10 to size
        "jge endII\n\t" // jump to endII if r10 is greater than or equal to size
        "movl (%0, %%r8, 4), %%r11d\n\t" // move source[r8] to r11
        "movb %%r11b, (%1, %%r10)\n\t" // move r11 to dest[r10]
        "inc %%r8\n\t" // increment r8
        "add $3, %%r10\n\t" // add 3 to r10
        "jmp startII\n\t" // jump to startII
        // outside loop
        "endII:\n\t"
        "inc %%r9\n\t" // increment r9
        "jmp startI\n\t" // jump to startI
        "endI:\n\t" // endI:
        :
        :"r"(source), "r"(dest), "r"(size)
        :"r8", "r9", "r10", "r11"
    );
    printf("Non-optimized looping:\n %s\n", dest);
}

void prettyFormattingFaster(int *source, char *dest, int size)
{
    asm(
        "movq $0, %%r8\n\t" // move 0 into r8
        "movq $0, %%r9\n\t" // move 0 into r9
        "strtI:\n\t"
        "cmpq $3, %%r9\n\t" // compare r9 to 3
        "jge ndI\n\t" // jump to endI if r9 is greater than or equal to 3
        "movq %%r9, %%r10\n\t" // move r9 into r10
        // nested loop
        "strtII:\n\t"
        "add $3, %%r10\n\t" // add 3 to r10
        "inc %%r8\n\t" // increment r8
        "cmpl %2, %%r10d\n\t" // compare r10 + 3 to size
        "jge ndII\n\t" // jump to endII if r10 + 3 is greater than or equal to size
        "movl (%0, %%r8, 4), %%r11d\n\t" // move source[r8 + 1] to r11
        "movb %%r11b, (%1, %%r10)\n\t" // move r11 to dest[r10 + 3]
        "dec %%r8d\n\t"
        "sub $3, %%r10\n\t"
        "movl (%0, %%r8, 4), %%r11d\n\t" // move source[r8] to r11
        "movb %%r11b, (%1, %%r10)\n\t" // move r11 to dest[r10]
        "inc %%r8\n\t" // increment r8
        "add $3, %%r10\n\t" // add 3 to r10
        "jmp strtII\n\t" // jump to startII
        // outside loop
        "ndII:\n\t"
        "inc %%r9\n\t" // increment r9
        "jmp strtI\n\t" // jump to startI
        "ndI:\n\t" // endI:
        :
        :"r"(source), "r"(dest), "r"(size)
        :"r8", "r9", "r10", "r11"
    );
    printf("Optimized looping:\n %s\n", dest);
}