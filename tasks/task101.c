/*
101. Дана последовательность целых чисел. Получить упорядоченную
     по невозрастанию последовательность, состоящую из членов данной
     последовательности, заключенных между первым и последним четными
     членами данной последовательности.
*/

#include <stdio.h>

#define LENGTH_LESS_THEN_ZERO   "Введённая длина массива меньше 0"
#define NO_NEGATIVES_NUMBERS    "В ведённом массиве нету отрицательных чисел"

int getSeqLength() {
    int len = -1;
    printf("Введите количество элементов последовательности: ");
    scanf("%d", &len);
    return len;
}

void getSeq(int *arr, int arrLength) {
    printf("Введите последовательность чисел (каждое с новой строки):\n");
    for (int iter = 0; iter < arrLength; iter++) {
        scanf("%d", arr + iter);
    }
}

void findFirstAndLastEvenNumbers(int *arr, int arrLength, int *firstEvenIndex, int *lastEvenIndex) {
    for (int iter = 0; iter < arrLength; iter++) {
        if (*(arr + iter) % 2 == 0) {
            if (*firstEvenIndex == -1) {
                *firstEvenIndex = iter;
            }
            *lastEvenIndex = iter;
        }
    }
}

void getSlice(int *enteredArr,  int length, int *newArr, int newLength, int startIndex, int endIndex) {
    for (int iter = startIndex; iter < endIndex + 1; iter++) {
        *(newArr + iter - startIndex) = *(enteredArr + iter);
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

void printArray(int *arr, int size) {
    printf("Получившийся список:\n");
    for (int iter = 0; iter < size; iter++) {
        printf("%d ", *(arr + iter));
    }
    printf("\n");
}

int main() {
    int resultStatus = 0;
    int length = getSeqLength();

    if (length < 0) {
        resultStatus = 1;
    } else {
        int enteredArr[length];

        getSeq(enteredArr, length);

        int firstEvenIndex = -1, lastEvenIndex = -1;
        findFirstAndLastEvenNumbers(enteredArr, length, &firstEvenIndex, &lastEvenIndex);

        if (firstEvenIndex == -1 || lastEvenIndex == -1) {
            resultStatus = 2;
        } else {            
            int resultLength = lastEvenIndex - firstEvenIndex + 1;
            int resultArray[resultLength];
            getSlice(enteredArr, length, resultArray, resultLength, firstEvenIndex, lastEvenIndex);
            
            reversedBubbleSort(resultArray, resultLength);
            
            printArray(resultArray, resultLength);
        }
    }
    switch (resultStatus)
    {
    case 1:
        printf("%s\n", LENGTH_LESS_THEN_ZERO);
    case 2:
        printf("%s\n", NO_NEGATIVES_NUMBERS);
    }
    return resultStatus;
}