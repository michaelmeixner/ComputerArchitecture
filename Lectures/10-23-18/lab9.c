// CSCI-4200 Lab 9
// Michael Meixner

#include <stdio.h>
#include <time.h>

// Test Data

#define count1 10
int t1a[count1] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int t1b[count1] = {5, 4,-3, 0, 1,-8, 5, 2, 4, 6};

#define count2 7
int t2a[count2] = {1, 2, 3, 4, 5, 6, 7};
int t2b[count2] = {8, 9, 0, 1, 2, 3, 4};

#define count3 11
int t3a[count3] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 7};
int t3b[count3] = {1, 2, 3, 5, 7, 1, 2, 3, 5, 7, 9};

#define count4 13
int t4a[count4] = {1, 3, 5, 7, 9, 9, 7, 5, 3, 1, 6, 1, 6};
int t4b[count4] = {6, 1, 6, 4, 1, 3, 3, 1, 4, 6, 1, 6, 7};

#define count5 9
int t5a[count5] = {1, 9, 2, 8, 3, 7, 4, 8, 5};
int t5b[count5] = {4, 5, 3, 6, 2, 7, 1, 8, 9};

#define count6 10000000
int t6a[count6];
int t6b[count6];

// end Test Data

int inner(int* x, int* y, int n, time_t *cycles)
{
   // computes the inner product of two arrays without loop unrolling

        int i;
        int product = 0;
        time_t start, end;

        start = clock();
        for (i = 0; i < n; i++)
        {
                product = product + (x[i] * y[i]);
        }
        end = clock();
        *cycles = (end - start);

        return product;
}

int inner2(int* x, int* y, int n, time_t *cycles)
{
        // computes the inner product of two arrays with loop unrolling

        int i;
        int product = 0, product1 = 0, product2 = 0;
        time_t start, end;

        start = clock();
        for(i = 0; i < n; i++, i++)
        {
                product1 += (x[i] * y[i]);
                product2 += (x[i+1] * y[i+1]);
        }
        product = product1 + product2;
        end = clock();
        *cycles = (end - start);

        return product;
}

int inner5(int* x, int* y, int n, time_t *cycles)
{
        int i;
        int product = 0;
        time_t start, end;

        start = clock();
        for(i = 0; i < n; i += 5)
        {
                product = product + (x[i] * y[i]) + (x[i+1] * y[i+1]) + (x[i+2] * y[i+2]) + (x[i+3] * y[i+3]) + (x[i+4] * y[i+4]);
        }
        end = clock();
        *cycles = (end - start);

        return product;
}

void main()
{
        int product1, product2, product3, product4, product5, product6;
        time_t times[6];

        product1 = inner(t1a,t1b,count1, times);
        product2 = inner(t2a,t2b,count2, &times[1]);
        product3 = inner(t3a,t3b,count3, &times[2]);
        product4 = inner(t4a,t4b,count4, &times[3]);
        product5 = inner(t5a,t5b,count5, &times[4]);
        product6 = inner(t6a,t6b,count6, &times[5]);

        double average = 0;
        for(int i = 0; i < 6; i++)
        {
                average += times[i];
                printf("%ld ", times[i]);
        }
        printf("\nAverage cycles = %lf\n", (average / 6));

        // printf("Products without loop unrolling are %d %d %d %d %d\n\n",
        // product1, product2, product3, product4, product5);

        //Uncomment these lines after inner2 is written.

        product1 = inner2(t1a,t1b,count1, times);
        product2 = inner2(t2a,t2b,count2, &times[1]);
        product3 = inner2(t3a,t3b,count3, &times[2]);
        product4 = inner2(t4a,t4b,count4, &times[3]);
        product5 = inner2(t5a,t5b,count5, &times[4]);
        product6 = inner2(t6a,t6b,count6, &times[5]);

        printf("\nInner 2:\n");
        average = 0;
        for(int i = 0; i < 6; i++)
        {
                average += times[i];
                printf("%ld ", times[i]);
        }
        printf("\nAverage cycles = %lf\n", (average / 6));

        // printf("Products with loop unrolling by a factor of 2 are %d %d %d %d %d\n\n",
        // product1, product2, product3, product4, product5);

        product1 = inner5(t1a,t1b,count1, times);
        product2 = inner5(t2a,t2b,count2, &times[1]);
        product3 = inner5(t3a,t3b,count3, &times[2]);
        product4 = inner5(t4a,t4b,count4, &times[3]);
        product5 = inner5(t5a,t5b,count5, &times[4]);
        product6 = inner5(t6a,t6b,count6, &times[5]);

        printf("\nInner 5:\n");
        average = 0;
        for(int i = 0; i < 6; i++)
        {
                average += times[i];
                printf("%ld ", times[i]);
        }
        printf("\nAverage cycles = %lf\n", (average / 6));

        // printf("Products with loop unrolling by a factor of 5 are %d %d %d %d %d\n\n",
        // product1, product2, product3, product4, product5);

}

// Hi I'm here to make your code look really weird for the sake of speed