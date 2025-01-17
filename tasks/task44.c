/*
44. Из последовательности целых чисел вывести в порядке возрастания числа,
    стоящие на четных местах и встречающиеся более двух раз.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS_COUNT 1000

int getSeqLen(int *elemCount) {

    printf("Программа принимает максимум 1000 чисел!\nВведите количество элементов: \n");
    scanf("%d", elemCount);
    return (0 < *elemCount && *elemCount <= MAX_ELEMENTS_COUNT);
}

void getUserInput(int elemCount, int *arrIn) {
    
    printf("Введите элементы последовательности (каждое с новой строки):\n");
    
    for (int iter = 0; iter < elemCount; iter++) {
        scanf("%d", &arrIn[iter]);
    }
}

int repeatsCount(int num, int *arr, int size) {

    int counter = 0;

    for (int iter = 0; iter < size; iter++) {
        if (arr[iter] == num) {
            counter += 1;
        }
    }

    return counter;
}

void searchEvenRepeats(int sizeIn, int *arrIn, int **arrOut, int *resSize) {

    *arrOut = (int *)malloc(sizeof(int) * sizeIn);

    int insertIndex = 0;
    for (int iter = 0; iter < sizeIn; iter += 2) {
       if (repeatsCount(arrIn[iter], arrIn, sizeIn) > 2 && repeatsCount(arrIn[iter], *arrOut, *resSize) == 0) {
            (*arrOut)[insertIndex] = arrIn[iter];
            insertIndex++;
            *resSize = insertIndex;
        };
    }
}

void printResult(int *arr, int size) {

    if (size == 0) {
        printf("Нет чисел, которые удовлетворяют условиям.\n");
    } else {
        printf("Получившийся массив:\n");

        for (int iter = 0; iter < size; iter++) {
            printf("%d\n", arr[iter]);
        }
    }
}

void swap(int* const a, int* const b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int size) {
    for (int iter=0; iter < size - 1; iter++) {
        for (int cur = 0; cur < size - iter - 1; cur++) {
            if (*(arr + cur) > *(arr + cur + 1))
                swap(arr + cur, arr + cur + 1);
        }
    }
}

int main() {

    int elemCount = 0;
    if (getSeqLen(&elemCount)) {
        int inputArray[elemCount];
        getUserInput(elemCount, inputArray);

        int *resultArray;
        int resultSize = 0;
        searchEvenRepeats(elemCount, inputArray, &resultArray, &resultSize);

        bubbleSort(resultArray, resultSize);
        printResult(resultArray, resultSize);
    } else {
        printf("Некоректное число элементов последовательности!");
    }
    
    return 0;
}
