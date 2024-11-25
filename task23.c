/*
23. Дан треугольник ABC в декартовой системе координат: A(x1,y1), B(x2,y2), C(x3,y3).
    Определить, является ли данный треугольник равносторонним, равнобедренным или разносторонним.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

#define EPS 1e-7

int isEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

void getUserInput(double *x1, double *y1, double *x2, double *y2, double *x3, double *y3) {
    
    printf("Введите координаты точки A через пробел:\n");
    scanf("%lf %lf", x1, y1);
    printf("Введите координаты точки B через пробел:\n");
    scanf("%lf %lf", x2, y2);
    printf("Введите координаты точки C через пробел:\n");
    scanf("%lf %lf", x3, y3);
}

double getSideLength(double *x1, double *y1, double *x2, double *y2) {

    double diffX = abs(*x2 - *x1);
    double diffY = abs(*y2 - *y1);
    return sqrt(pow(diffX, 2) + pow(diffY, 2));
}

void getTriangleType(double *x1, double *y1, double *x2, double *y2, double *x3, double *y3, char *str) {

    double ab = getSideLength(x1, y1, x2, y2);
    double bc = getSideLength(x2, y2, x3, y3);
    double ca = getSideLength(x3, y3, x1, y1);

    if (isEqual(ab, bc) && isEqual(bc, ca)) {
        strcpy(str, "Треугольник равносторонний");
    } else if (isEqual(ab, bc) || isEqual(bc, ca) || isEqual(ca, ab)) {
        strcpy(str, "Треугольник равнобедренный");
    } else {
        strcpy(str, "Треугольник разносторонний");
    }
}

int main() {

    double x1, x2, x3, y1, y2, y3;
    getUserInput(&x1, &y1, &x2, &y2, &x3, &y3);

    char resultText[53];

    getTriangleType(&x1, &y1, &x2, &y2, &x3, &y3, resultText);
    printf("%s\n", resultText);

    return 0;
}
