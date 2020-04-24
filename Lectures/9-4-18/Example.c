#include "Example.h" //the quotation marks tell preprocessor this is part of your own package
#include <stdio.h> //the angle brackets tell preprocessor that the package is included in default c package

void doSomethingElse();

void doSomething()
{
    //do work here
    doSomethingElse(4, 5);
}

void doSomethingElse(int x, int y)
{
    //do work here
}