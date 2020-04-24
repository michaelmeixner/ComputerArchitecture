#include <stdio.h>

int addLoop(int a, int b)
{
    int result = 0;
    for(int i = 0; i < 5; i++)
    {
        result += a + b;
    }
    return result;
}

int addLoopUnrolled(int a, int b)
{
    int result = 0;
    for(int i = 0; i < 1; i++)
    {
        result = result + a + b;
        result = result + a + b;
        result = result + a + b;
        result = result + a + b;
        result = result + a + b;
    }
    return result;
}

int multLoop(int a, int b)
{
    int result = 0;
    for(int i = 0; i < 5; i++)
    {
        result += a * b;
        a++;
        b++;
    }
    return result;
}

int multLoopUnrolled(int a, int b)
{
    int result = 0;
    for(int i = 0; i < 2; i++)
    {
        result += ((a+1) * (b+1)) + ((a+2) * (b+2));
        a++;
        b++;
    }
    result = result + (a * b);
    return result;
}

int main()
{
    printf("The result of adding 5 times is %d\n", addLoop(1, 1));
    printf("The unrolled result of adding 5 times is %d\n", addLoopUnrolled(1, 1));
    printf("The result of multLoop function is %d\n", multLoop(1, 1));
    printf("The result of unrolled multLoop function is %d\n", multLoopUnrolled(1, 1));
}