/*
15. Определить, можно ли данное натуральное число представить
    в виде суммы квадратов двух натуральных чисел.
*/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int getInput(int *num) {
    printf("Введите натурально число:\n");
    
    int status;
    status = scanf("%d", num);
    
    if (status != 1 || *num <= 0) {
        printf("Некорректный ввод\n");
        status = -1;
    }
    
    return status;
}

bool canTransform(int num, int *a, int *b) {
    bool isFound = 0;
    
    for (int iter = sqrt(num) + 1; iter > 0 && !isFound; iter--) {
        *b = sqrt(num - iter * iter);
        if (*b * *b + iter * iter == num && *b != 0) {
            isFound = 1;
            *a = iter;
        }
    }
    
    return isFound;
}

int main() {
    int enteredNum;
    int status = 0;

    status = getInput(&enteredNum);

    if (status != -1) {
        int numA, numB;
        bool numIsFound = canTransform(enteredNum, &numA, &numB);
        if (numIsFound) {
            printf("Данное число можно представить в виде:\n");
            printf("%d^2 + %d^2 = %d + %d = %d\n", numA, numB, numA * numA, numB * numB, enteredNum);
        } else {
            printf("Данное число нельзя представить в виде суммы квадратов двух натуральных.");
        }
    }

    return status;
}