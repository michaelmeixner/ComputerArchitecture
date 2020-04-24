// Michael Meixner, Lab 11

#include <stdio.h>

#define N 3
typedef int array[N][N]; // N by N matrix

void transpose(array src, array dst)
{
   int i, j, offset;

   for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
          dst[j][i] = src[i][j];
          offset = (N * j) + i;
        }
    }
    printf("The k-value is %d\n", offset);
}

int main()
{
   array mat, mat_trans;

   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < N; j++)
      {
          mat[i][j] = 10 * i + j;
      }
   }

   transpose(mat, mat_trans);
}
