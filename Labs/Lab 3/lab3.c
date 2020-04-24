// Michael Meixner CSCI-4200 Lab 3
#include <stdio.h>

long lab3(long a, long b)
{
    while (a != b)
        if (a < b)
            a = b - a;
        else
            a = a - b;

    return a;
}

int main()
{
    printf("%ld\n", lab3(36, 4));
}