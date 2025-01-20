/*
    Дана квадратная матрица.
    Заменить предпоследний столбец первой из строк,
    в которой находится максимальный элемент.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int getMatrixSize() {
    printf("Программа работает с матрицей NxN.\n");
    printf("Введите N: ");

    int size = 0;
    scanf("%d", &size);

    return size;
}

int getEnteredMatrixElement(const int row, const int col) {
    printf("Введите элемент %d строки %d столбца: ", row + 1, col + 1);

    int element;
    scanf("%d", &element);

    return element;
}

void getEnteredSquareMatrix(int **matrix, const int matrixSize) {
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
            const int element = getEnteredMatrixElement(row, col);
            matrix[row][col] = element;
        }
    }
}

void freeMatrix(int **matrix, const int matrixSize) {
    for (int row = 0; row < matrixSize; row++) {
        free(matrix[row]);
    }
    free(matrix);
}

void printSquareMatrix(int **matrix, const int matrixSize) {
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
            printf("%d ", matrix[row][col]);
        }
        putchar('\n');
    }
}

void replacePenultimateColumnToString(int **matrix, const int matrixSize,
                                        const int stringIndex) {
    const int penultimateColumn = matrixSize - 2;
    for (int currentIndex = 0; currentIndex < matrixSize; currentIndex++) {
        matrix[currentIndex][penultimateColumn] = matrix[stringIndex][currentIndex];
    }
}

int findStringContainingElement(int **matrix, const int matrixSize,
                                const int targetElement) {
    /*
        Возвращает первый индекс строки, в которой
        содержится заданный элемент
    */
    int currentColumn = 0, currentRow = 0;
    bool isContained = false;

    while (currentRow < matrixSize && !isContained) {
        if (currentColumn == matrixSize) {
            currentColumn = 0;
            currentRow++;
        }

        if (matrix[currentRow][currentColumn] == targetElement) {
            isContained = true;
        }

        currentColumn++;
    }

    return isContained ? currentRow : -1;
}

int findMaxElement(int **matrix, const int matrixSize) {
    int maxElement = matrix[0][0];

    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
            if (matrix[row][col] > maxElement) {
                maxElement = matrix[row][col];
            }
        }
    }

    return maxElement;
}

int main() {
    const int matrixSize = getMatrixSize();

    int **matrix = malloc(matrixSize * sizeof(int*));
    if (matrix == NULL) {
        return -1;
    }

    for (int iter = 0; iter < matrixSize; iter++) {
        matrix[iter] = (int*)malloc(matrixSize * sizeof(int));
    }

    getEnteredSquareMatrix(matrix, matrixSize);

    const int maxElement = findMaxElement(matrix, matrixSize);
    const int targetString = findStringContainingElement(matrix, matrixSize,
                                                        maxElement);

    replacePenultimateColumnToString(matrix, matrixSize, targetString);

    printSquareMatrix(matrix, matrixSize);

    freeMatrix(matrix, matrixSize);

    return 0;
}
