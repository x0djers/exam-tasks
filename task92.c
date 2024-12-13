/*
92. Дано m точек в n-мерном пространстве. Упорядочить точки по неубыванию их
    расстояний до начала координат.
*/

#include <stdio.h>
#include <math.h>

int getDimension() {
    int dimension = 0;
    printf("Введите размерность пространства: ");
    scanf("%d", &dimension);
    return dimension;
}

int getCountOfPoints() {
    int count = 0;
    printf("Введите количество точек: ");
    scanf("%d", &count);
    return count;
}

double calculateDistance(double *arrOfCoords, int n) {
    double distance = 0;
    for (int iter = 0; iter < n; iter++) {
        distance += pow(arrOfCoords[iter], 2);
    }
    return sqrt(distance);
}

void getUserInput(int countOfPoints, int dimension, double arrOfPoints[countOfPoints][dimension]) {
    for (int iter = 0; iter < countOfPoints; iter++) {
        for (int i = 0; i < dimension; i++) {
            printf("Введите %d координату %d точки: ", i + 1, iter + 1);
            scanf("%lf", &arrOfPoints[iter][i]);
        }
    }
}

void sortPoints(int countOfPoints, int dimension, double arr[countOfPoints][dimension]) {
    for (int iter = 0; iter < countOfPoints - 1; iter++) {
        for (int j = iter + 1; j < countOfPoints; j++) {
            if (calculateDistance(arr[iter], dimension) > calculateDistance(arr[j], dimension)) {
                double temp[dimension];
                for (int k = 0; k < dimension; k++) {
                    temp[k] = arr[iter][k];
                    arr[iter][k] = arr[j][k];
                    arr[j][k] = temp[k];
                }
            }
        }
    }
}

void printResult(int countOfPoints, int dimension, double arr[countOfPoints][dimension]) {
    for (int i = 0; i < countOfPoints; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("%.11lf ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int dimension = getDimension();
    int countOfPoints = getCountOfPoints();

    double arrOfPoints[countOfPoints][dimension];
    getUserInput(countOfPoints, dimension, arrOfPoints);

    sortPoints(countOfPoints, dimension, arrOfPoints);

    printResult(countOfPoints, dimension, arrOfPoints);
    return 0;
}