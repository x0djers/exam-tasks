/*
108. Напиши программу для вычисления
     определителя матрицы размерами 3x3.
*/

#include <math.h>
#include <stdio.h>
#include <stdint.h>

int getMatrixSize(int *matrixSize, int *statusCode) {
    printf("Введите размер квадратной матрицы:\n");
    if (scanf("%d", matrixSize) != 1)
        *statusCode = -1;

    if (*matrixSize < 2)
        *statusCode = -1;
}

void getMatrix(int *matrix, int size) {
    printf("Введите числа матрицы размером %dx%d (каждое с новой строки):\n", size, size);
    for (int iter = 0; iter < size * size; iter++) {
        scanf("%d", &matrix[iter]);
    }
}

void printMatrix(int *matrix, int rowC, int colC) {
    printf("\nВведённая матрица:\n\n");
    for (int i = 0; i < rowC; i++) {
        printf("| ");
        for (int j = 0; j < colC; j++) {
            printf("%*d", 10, matrix[i * rowC + j]);
        }
        printf("%*s|\n", 10, "");
    }
    printf("\n");
}

void genMatrix(int *matrix, int currentRow, int currentCol, int rowC, int colC, int* newMtrx) {

    int insertIndex = 0;

    for (int i = 0; i < rowC; i++) {
        for (int j = 0; j < colC; j++) {
            if (i != currentRow && j != currentCol) {
                newMtrx[insertIndex++] = matrix[i * rowC + j];
            }
        }
    }
}

int64_t findDet(int *matrix, int rowC, int colC) {
    int64_t result = 0;
    if (rowC == 2) {
        int64_t determinant = matrix[0] * matrix[3] - matrix[1] * matrix[2];
        result = determinant;
    } else {
        int sign = 0;
        for (int i = 0; i < colC; i++) {
            int newMtrx[rowC - 1][colC - 1];
            genMatrix(matrix, 0, i, rowC, colC, (int *)newMtrx);
            result += matrix[i] * findDet((int *)newMtrx, rowC - 1, colC - 1) * pow(-1, sign++);
        }
    }
    return result;
}

int main() {
    int statusCode = 0;
    int matrixSize = 0;
    statusCode = getMatrixSize(&matrixSize, &statusCode);
    
    if (statusCode != 0) {
        int matrix[matrixSize][matrixSize];
        getMatrix((int*)matrix, matrixSize);

        printMatrix((int*)matrix, matrixSize, matrixSize);

        int64_t result = findDet((int*)matrix, matrixSize, matrixSize);

        printf("det Matrix = %lld", result);
    }

    return 0;
}