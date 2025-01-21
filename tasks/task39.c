/*
39. Определить, является ли четырехугольник ABCD, где
    A(x1,y1), B(x2,y2), C(x3,y3), D(x4,y4), квадратом.
*/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    double x;
    double y;
} Point;

bool isSquare(Point A, Point B, Point C, Point D) {
    bool answer = false;

    double ABx = B.x - A.x;
    double ABy = B.y - A.y;
    double BCx = C.x - B.x;
    double BCy = C.y - B.y;
    double CDx = D.x - C.x;
    double CDy = D.y - C.y;
    double DAx = A.x - D.x;
    double DAy = A.y - D.y;
    double ACx = C.x - A.x;
    double ACy = C.y - A.y;
    double BDx = D.x - B.x;
    double BDy = D.y - B.y;

    double AB = sqrt(ABx * ABx + ABy * ABy);
    double BC = sqrt(BCx * BCx + BCy * BCy);
    double CD = sqrt(CDx * CDx + CDy * CDy);
    double DA = sqrt(DAx * DAx + DAy * DAy);
    double AC = sqrt(ACx * ACx + ACy * ACy);
    double BD = sqrt(BDx * BDx + BDy * BDy);

    if (AB == BC && BC == CD && CD == DA && DA == AB && AC == BD) {
        answer = true;
    } else {
        answer = false;
    }
    return answer;
}

void getPoint(Point *point, char pointName) {
    printf("Введите %c(x, y) через пробел: ", pointName);
    scanf("%lf %lf", &point->x, &point->y);
}

int main() {
    Point A, B, C, D;
    getPoint(&A, 'A');
    getPoint(&B, 'B');
    getPoint(&C, 'C');
    getPoint(&D, 'D');

    bool result = isSquare(A, B, C, D);

    if (result) {
        printf("Четырехугольник ABCD является квадратом\n");
    } else {
        printf("Четырехугольник ABCD не является квадратом\n");
    }

    return 0;
}
