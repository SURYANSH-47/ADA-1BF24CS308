#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int board[10];int solution_count = 1;

int place(int row, int column) {
    for (int j = 1; j < row; j++) {
        if (board[j] == column || (abs(board[j] - column) == abs(j - row))) {
            return 0; 
        }
    }
    return 1; 
}

void print(int n) {
    
    printf("\nSOLUTION %d:\n", solution_count++);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j) {
                printf("Q  "); 
            } else {
                printf(".  "); 
            }
        }
        printf("\n");
    }
}

void queens(int row, int n) {
    for (int j = 1; j <= n; j++) {
        if (place(row, j) == 1) {
            board[row] = j; 
            
            if (row == n) {
                print(n); 
            } else {
                queens(row + 1, n); 
            }
            
            board[row] = 0; 
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    
    queens(1, n);
    return 0;
}