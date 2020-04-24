void doSomething()
{
    int x = 4; //the 4 is stored in the chunk of memory that x is pointing to
    int y = 2; //the 2 is stored in the chunk of memory that y is pointing to
    doSomethingElse(&x, &y); //we are getting the address (specific chunk of memory) of x and y with the "&" symbol
}

void doSomethingElse(int *x, int *y) //here, the asterisk is just saying that x and y are pointers
{
    *x += *y; //here, the asterisk is acting as the dereference operator (able to change the contents of the chunk of memory; if you didn't have that symbol, you would point to a new chunk of memory altogether)
}

//scanf is a function that takes the address of a variable and stores something in that location
scanf("%d", &x); //goes to the address x and finds what's stored there
scanf("%d", x);  //places what is at x in that spot