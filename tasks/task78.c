/*
78. Дана последовательность целых чисел, все элементы которой различны.
    Вывести в порядке убывания те члены последовательности, которые не находятся
    между минимальным и максимальным.
*/

#include <stdio.h>

#define MAX_ELEMENTS_COUNT 1000

int getSeqLen(int *elemCount) {
    printf("Программа принимает максимум 1000 чисел!\nВведите количество элементов: ");
    scanf("%d", elemCount);
    return (0 < *elemCount && *elemCount <= MAX_ELEMENTS_COUNT);
}

void getSeqInput(int elemCount, int *arrIn) {
    printf("Введите элементы последовательности (каждое с новой строки):\n");
    
    for (int iter = 0; iter < elemCount; iter++) {
        scanf("%d", &arrIn[iter]);
    }
}

int findMinIndexOfArr(int *arr, int size) {
    int minIndex = 0;
    for (int iter = 1; iter < size; iter++) {
        if (arr[iter] < arr[minIndex]) {
            minIndex = iter;
        }
    }
    return minIndex;
}

int findMaxIndexOfArr(int *arr, int size) {
    int maxIndex = 0;
    for (int iter = 1; iter < size; iter++) {
        if (arr[iter] > arr[maxIndex]) {
            maxIndex = iter;
        }
    }
    return maxIndex;
}

void getSlice(int startPassIndex, int endPassIndex, int *arrIn, int arrInSize, int *arrOut, int arrOutSize) {
    int insertionIndex = 0;

    for (int iter = 0; iter < arrInSize; iter++) {
        if (iter < startPassIndex || iter > endPassIndex) {
            arrOut[insertionIndex++] = arrIn[iter];
        }
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

void reversedBubbleSort(int *arr, int size) {
    for (int iter=0; iter < size - 1; iter++) {
        for (int cur = 0; cur < size - iter - 1; cur++) {
            if (*(arr + cur) < *(arr + cur + 1))
                swap(arr + cur, arr + cur + 1);
        }
    }
}

int main() {

    int elemCount = 0;
    if (getSeqLen(&elemCount)) {
        int inputArray[elemCount];

        getSeqInput(elemCount, inputArray);
        
        int minIndex = findMinIndexOfArr(inputArray, elemCount);
        int maxIndex = findMaxIndexOfArr(inputArray, elemCount);

        if (minIndex > maxIndex){
            swap(&minIndex, &maxIndex);
        }
                
        int outArraySize = elemCount - (maxIndex - minIndex + 1);
        
        int resultArray[outArraySize];

        getSlice(minIndex, maxIndex, inputArray, elemCount, resultArray, outArraySize);
        reversedBubbleSort(resultArray, outArraySize);
        printResult(resultArray, outArraySize);

    } else {
        printf("Некоректное число элементов последовательности!");
    }
    return 0;
}
