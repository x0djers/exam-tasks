/*
6.  Если целое число x встречается в данной последовательности целых чисел, то
    упорядочить по неубыванию часть последовательности после первого вхождения x.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS_COUNT 1000

int getSeqLen(int *elemCount) {
    printf("Программа принимает максимум 1000 чисел!\nВведите количество элементов: ");
    scanf("%d", elemCount);
    return (0 < *elemCount && *elemCount <= MAX_ELEMENTS_COUNT);
}

int getXInput() {
    int xNum;
    printf("Введите целое число x: ");
    scanf("%d", &xNum);
    return xNum;
}

void getSeqInput(int elemCount, int *arrIn) {
    printf("Введите элементы последовательности (каждое с новой строки):\n");
    
    for (int iter = 0; iter < elemCount; iter++) {
        scanf("%d", &arrIn[iter]);
    }
}

int findMinIndexOf(int num, int *arr, int size) {

    int numIndex = -1;
    for (int iter = size - 1; iter > 0; iter--) {
        if (num == arr[iter]) {
            numIndex = iter;
        }
    }
    
    return numIndex;
}

void getSlice(int startIndex, int endIndex, int *arrIn, int **arrOut) {
    
    int arrSize = endIndex - startIndex + 1;
    *arrOut = (int *)malloc(sizeof(int) * arrSize);
    for (int iter = startIndex; iter <= endIndex; iter++) {
        (*arrOut)[iter - startIndex] = arrIn[iter];
    }
}

void printResult(int *arr, int size) {
    printf("Упорядоченная часть последовательности: ");
    for (int iter = 0; iter < size; iter++) {
        printf("%d ", arr[iter]);
    }
    printf("\n");
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
        int x = getXInput();
        getSeqInput(elemCount, inputArray);
        
        int firstIndexOfX = findMinIndexOf(x, inputArray, elemCount);
        
        int *resultArray;
        if (firstIndexOfX != -1) {
            int sizeFromIndex = elemCount - firstIndexOfX;

            getSlice(firstIndexOfX, firstIndexOfX + sizeFromIndex, inputArray, &resultArray);
            bubbleSort(resultArray, sizeFromIndex);
            printResult(resultArray, sizeFromIndex);

            free(resultArray);
        } else {
            printf("Число %d не найдено.", x);
        }
    } else {
        printf("Некоректное число элементов последовательности!");
    }
    return 0;
}
