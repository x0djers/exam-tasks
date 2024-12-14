/*
17. Если в целочисленной последовательности нет других чисел, кроме
    данных x, y, z, то упорядочить последовательность по невозрастанию.
*/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_ARRAY_LENGTH 1000

void getArrLen(int *elemCount) {
    printf("Программа принимает максимум 1000 чисел!\nВведите количество элементов: ");
    scanf("%d", elemCount);
}

void checkIsXYZ(int elem, int x, int y, int z, bool *onlyXYZ) {
    if (elem != x && elem != y && elem != z) {
        *onlyXYZ = false;
    }
}

void getArrInput(int elemCount, int *arrIn, bool *onlyXYZ, int x, int y, int z) {
    printf("Введите элементы последовательности (каждое с новой строки):\n");
    
    for (int iter = 0; iter < elemCount; iter++) {
        scanf("%d", &arrIn[iter]);
        checkIsXYZ(arrIn[iter], x, y, z, onlyXYZ);
    }
}

void swap(int* const a, int* const b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reversedBubbleSort(int *arr, int size) {
    for (int iter=0; iter < size - 1; iter++) {
        for (int cur = 0; cur < size - iter - 1; cur++) {
            if (*(arr + cur) < *(arr + cur + 1))
                swap(arr + cur, arr + cur + 1);
        }
    }
}

void getXYZ(int *x, int *y, int *z) {
    printf("Введите x y z (через пробел):\n");
    int count = scanf("%d %d %d", x, y, z);
}

void printResult(int *arr, int size) {
    printf("Упорядоченная часть последовательности: ");
    for (int iter = 0; iter < size; iter++) {
        printf("%d ", arr[iter]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_ARRAY_LENGTH];
    int x = 0, y = 0, z = 0;
    bool onlyXYZ = true;
    int arrayLength = 0;

    getXYZ(&x, &y, &z);
    getArrLen(&arrayLength);
    getArrInput(arrayLength, arr, &onlyXYZ, x, y, z);

    if (onlyXYZ) {
        reversedBubbleSort(arr, arrayLength);
        printResult(arr, arrayLength);
    } else {
        printf("Последовательность содержит посторонние элементы\n");
    }
    return 0;
}