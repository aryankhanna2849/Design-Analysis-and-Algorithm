#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2  // Matrix size (for Strassen, must be power of 2)

// Function to print a matrix
void printMatrix(int size, int mat[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Traditional matrix multiplication
void traditionalMultiply(int size, int A[size][size], int B[size][size], int C[size][size]) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// Strassen's Matrix Multiplication (for 2x2 matrices)
void strassenMultiply(int A[2][2], int B[2][2], int C[2][2]) {
    int M1, M2, M3, M4, M5, M6, M7;

    M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    M2 = (A[1][0] + A[1][1]) * B[0][0];
    M3 = A[0][0] * (B[0][1] - B[1][1]);
    M4 = A[1][1] * (B[1][0] - B[0][0]);
    M5 = (A[0][0] + A[0][1]) * B[1][1];
    M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}

int main() {
    int A[N][N], B[N][N], C1[N][N], C2[N][N];
    srand(time(NULL));

    // Generate random matrices
    printf("Matrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = rand() % 10;
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Traditional Multiplication
    clock_t start = clock();
    traditionalMultiply(N, A, B, C1);
    clock_t end = clock();
    double timeTraditional = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTraditional Multiplication Result:\n");
    printMatrix(N, C1);

    // Strassen Multiplication
    start = clock();
    strassenMultiply(A, B, C2);
    end = clock();
    double timeStrassen = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Strassen Multiplication Result:\n");
    printMatrix(N, C2);

    // Performance Comparison
    printf("Time taken (Traditional): %f sec\n", timeTraditional);
    printf("Time taken (Strassen):   %f sec\n", timeStrassen);

    return 0;
}
