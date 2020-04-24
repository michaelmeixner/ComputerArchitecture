#include <stdio.h>
#include <math.h>

int div16(int x)
{
    int k = 4;
    int result = 0;

    result = (x < 0 ? x + (1 << k) - 1 : x) >> k;

    return result;
}

int main()
{
    printf("This division yields %d\n", div16(32));
}