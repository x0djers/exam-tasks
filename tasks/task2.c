/*
2. Даны действительные числа x, y, z. Выяснить, существует
   ли треугольник с длинами сторон x, y, z. Если да, то
   является ли он остроугольным.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

#define EPS 1e-7

int isEqual(double a, double b) {
    return abs(a - b) < EPS;
}

void getUserInput(double *a, double *b, double *c){
    
    printf("Введите длину первой стороны: ");
    scanf("%lf", a);
    printf("Введите длину второй стороны: ");
    scanf("%lf", b);
    printf("Введите длину третьей стороны: ");
    scanf("%lf", c);
}

void swap(double *a, double *b) {

    double temp = *a;
    *a = *b;
    *b = temp;
}

void compareAndSwap(double *a, double *b) {

    if (*a > *b) 
        swap(a, b);
}

int checkTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a) && (!isEqual(a, 0)) && (!isEqual(b, 0)) && (!isEqual(c, 0));
}

int checkAngle(double sideX, double sideY, double sideZ) {

    compareAndSwap(&sideX, &sideY);
    compareAndSwap(&sideX, &sideZ);
    compareAndSwap(&sideY, &sideZ);

    return sideZ * sideZ < sideX * sideX + sideY * sideY;
}

int main() {

    double x, y, z;
    getUserInput(&x, &y, &z);

    char resultText[88] = "Треугольника не существует\0";

    if (checkTriangle(x, y, z)) {
        if (checkAngle(x, y, z)) {
            strcpy(resultText, "Треугольник сущетсвут и он остроугольный\0");
        } else {
            strcpy(resultText, "Треугольник существует, но он не остроугольный\0");
        }
    }
    
    printf("%s\n", resultText);

    return 0;
}
