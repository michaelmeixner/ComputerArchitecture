#include <stdio.h>
#include <math.h>

void gotocond(short a, short *p)
{
    if(a && *p < a)
        goto label1;
    
    label1:
        *p = a;
}