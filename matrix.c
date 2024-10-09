#include <stdio.h>
#define SIZE 5

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int output[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int output[SIZE][SIZE]);
void transposeMatrix(int m[SIZE][SIZE], int output[SIZE][SIZE]);
void printMatrix(int m[SIZE][SIZE]);

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    // function to be manipulated for the output
    int output[SIZE][SIZE];

    // addMatrices function
    addMatrices(m1, m2, output);
    printf("\nAdded Matrices:\n");
    printMatrix(output);

    // multiplyMatrices function
    multiplyMatrices(m1, m2, output);
    printf("\nMultiplied Matrices:\n");
    printMatrix(output);

    // transposeMatrix Function
    transposeMatrix(m1, output);
    printf("\nTranspose of Matrix 1:\n");
    printMatrix(output);

    // transposeMatrix Function
    transposeMatrix(m2, output);
    printf("\nTranspose of Matrix 2:\n");
    printMatrix(output);

    return 0;
}

void printMatrix(int m[SIZE][SIZE]){
    // row
    for (int i = 0; i < SIZE; i++) {
        // col
        for (int j = 0; j < SIZE; j++) {
            printf("%d, ", m[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int output[SIZE][SIZE]){
    //r ow
    for (int i=0; i<SIZE; i++){
        // col
        for (int j=0; j<SIZE; j++){
            output[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int output[SIZE][SIZE]){
    // row
    for (int i=0; i<SIZE; i++){
        // col
        for (int j=0; j<SIZE; j++){
            output[i][j] = m1[i][j] * m2[i][j];
        }
    }
}

void transposeMatrix(int m[SIZE][SIZE], int output[SIZE][SIZE]){
    // row
    for (int i = 0; i < SIZE; i++) {
        // col
        for (int j = 0; j < SIZE; j++) {
            output[j][i] = m[i][j];
        }
    }
}
