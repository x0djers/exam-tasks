/*
8. Определить, является ли четырехугольник ABCD, где
   A(x1,y1), B(x2,y2), C(x3,y3), D(x4,y4), прямоугольником.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

#define EPS 1e-7

int isEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

void getUserInput(double *x1, double *x2, double *x3, double *x4, double *y1, double *y2, double *y3, double *y4) {

    printf("Введите координаты точки A через пробел:\n");
    scanf("%lf %lf", x1, y1);
    printf("Введите координаты точки B через пробел:\n");
    scanf("%lf %lf", x2, y2);
    printf("Введите координаты точки C через пробел:\n");
    scanf("%lf %lf", x3, y3);
    printf("Введите координаты точки D через пробел:\n");
    scanf("%lf %lf", x4, y4);
}

double getSideLength(double *x1, double *y1, double *x2, double *y2) {
    
    double diffX = abs(*x2 - *x1);
    double diffY = abs(*y2 - *y1);
    return sqrt(diffX * diffX + diffY * diffY);
}

int isRectangle(double *x1, double *x2, double *x3, double *x4, double *y1, double *y2, double *y3, double *y4) {
    
    double d1 = getSideLength(x1, y1, x3, y3);
    double d2 = getSideLength(x2, y2, x4, y4);
    
    double ab = getSideLength(x1, y1, x2, y2);
    double bc = getSideLength(x2, y2, x3, y3);
    double cd = getSideLength(x3, y3, x4, y4);
    double da = getSideLength(x4, y4, x1, y1);

    return isEqual(d1, d2) && isEqual(ab, cd) && isEqual(bc, da);
}

int main() {

    double x1, x2, x3, x4, y1, y2, y3, y4;
    getUserInput(&x1, &x2, &x3, &x4, &y1, &y2, &y3, &y4);

    char resultText[92] = "Четырёхугольник не является прямоугольником\0";

    if (isRectangle(&x1, &x2, &x3, &x4, &y1, &y2, &y3, &y4)) {
        strcpy(resultText, "Данный четырёхугольник является прямоугольником");
    }
    
    printf("%s\n", resultText);

    return 0;
}