#include <stdio.h>

int main()
{
    int i, product;
    int a = 1;
    int b = 2;
    for(i = 0; i < 5; i++)
    {
        product = (a * b);
        a++;
        b++;
    }

    printf("Product is %d\n", product);
}