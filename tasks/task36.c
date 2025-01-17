/*
36. Напиши программу для вычисления обратной матрицы размерами 2x2.
*/

#include <stdio.h>
#include <math.h>


#define EPS 1e-9

int isEqual(double a, double b) {
    return abs(a - b) < EPS;
}

double findDeterminant(double matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

void findComplementMatrix(double inMatrix[2][2], double outMatrix[2][2]) {
    outMatrix[0][0] = inMatrix[1][1];
    outMatrix[0][1] = -inMatrix[1][0];
    outMatrix[1][0] = -inMatrix[0][1];
    outMatrix[1][1] = inMatrix[0][0];
}

void transponseMatrix(double inMatrix[2][2], double outMatrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            outMatrix[i][j] = inMatrix[j][i];
        }
    }
}

void inverseMatrix(double inMatrix[2][2], double outMatrix[2][2]) {
    double determinant = findDeterminant(inMatrix);
    double complementMatrix[2][2];
    double transposedMatrix[2][2];
    findComplementMatrix(inMatrix, complementMatrix);
    transponseMatrix(complementMatrix, transposedMatrix);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            outMatrix[i][j] = transposedMatrix[i][j] / determinant;
        }
    }
}


void getUserInput(double matrix[2][2]) {
    printf("Введите элементы матрицы построчно, слева направо:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void printMatrix(double matrix[2][2]) {
    printf("Обратная матрица:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double matrix[2][2];
    getUserInput(matrix);
    double matrixDeterminant = findDeterminant(matrix);
    if (isEqual(matrixDeterminant, 0.0)) {
        printf("Детерминант равен 0, обратной матрицы не существует\n");
    } else {
        double inversedMatrix[2][2];
        inverseMatrix(matrix, inversedMatrix);
        printMatrix(inversedMatrix);
    }
    return 0;
}
