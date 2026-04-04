#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20  // Maximum board size

int board[MAX];  // board[i] = column position of queen in row i

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check column and diagonals
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void solveNQueens(int row, int n) {
    if (row == n) {
        printBoard(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the value of n (size of board): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid board size. Please enter a value between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Solutions for %d-Queens problem:\n\n", n);
    solveNQueens(0, n);

    return 0;
}