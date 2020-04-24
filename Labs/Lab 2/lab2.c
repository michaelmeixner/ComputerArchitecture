#include <stdio.h>

int main()
{   
    // int x = 5;
    // printf("Variable x is located at %p\n", &x);
    // int *p = NULL;
    // p = &x;
    // printf("Pointer value of p is %p\n", p);
    // printf("Dereferenced value of p is %d, and x = %d\n", *p, x);int a = 42;
    // int b = 7;
    // int c = 999;
    // int *t = &a;
    // int *u = NULL;
    // printf("%d %d\n", a, *t);

    // c = b;
    // u = t;
    // printf("%d %d\n", c, *u);

    // a = 8;
    // b = 8;
    // printf("%d %d %d %d\n", b, c, *t, *u);

    // *t = 123;
    // printf("%d %d %d %d %d\n", a, b, c, *t, *u);

    // //new code
    // t = &c;
    // *t = 555;
    // printf("%d %d\n", c, *t);

    // c = 222;
    // printf("%d %d\n", c, *t);

    // int *v = t;  //you get a compiler error if you make *v = &t because they are incompatible pointer types
    // printf("%d\n", *v);

    printf("sizeof(char): %lu\n",   sizeof(char));
    printf("sizeof(42): %lu\n",     sizeof(42));
    printf("sizeof(float): %lu\n",  sizeof(float));
    printf("sizeof(double): %lu\n", sizeof(double));
    printf("sizeof(NULL): %lu\n",   sizeof(NULL));
    
    printf("sizeof(int): %lu\n",   sizeof(int));
    printf("sizeof(3.14): %lu\n",   sizeof(3.14));

    int d[3] = { 1, 2, 3 };
    printf("sizeof(d) = %lu\n", sizeof(d));
}