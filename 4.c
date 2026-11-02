#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define N 4
 
int main(void) {
    int A[N][N];  
    int x[N];      
    int c[N];      
    int i, j;
 
    srand((unsigned int)time(NULL));
 
  
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
        }
        x[i] = rand() % 10;
    }
 
    for (i = 0; i < N; i++) {
        c[i] = 0;
        for (j = 0; j < N; j++) {
            c[i] += A[i][j] * x[j];
        }
    }
 
    
    printf("Matriks A (4x4):\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
 
    printf("\nVektor x (4x1):\n");
    for (i = 0; i < N; i++) {
        printf("%4d\n", x[i]);
    }
 
    
    printf("\nHasil c = A x:\n");
    for (i = 0; i < N; i++) {
        printf("c[%d] = %d\n", i, c[i]);
    }
 
    return 0;
}