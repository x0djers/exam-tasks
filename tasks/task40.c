/*
40. Дана последовательность целых чисел. Упорядочить по невозрастанию
    часть данной последовательности, между предпоследним и последним
    отрицательными членами.
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

void findTwoLastNegative(int *arr, int arrLength, int *penultimateNegativeIndex, int *lastNegativeIndex) {
    for (int iter = 0; iter < arrLength; iter++) {
        if (*(arr + iter) < 0) {
            *penultimateNegativeIndex = *lastNegativeIndex;
            *lastNegativeIndex = iter;
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

        int penultimateNegativeIndex = -1, lastNegativeIndex = -1;
        findTwoLastNegative(enteredArr, length, &penultimateNegativeIndex, &lastNegativeIndex);

        if (penultimateNegativeIndex == -1 || lastNegativeIndex == -1) {
            resultStatus = 2;
        } else {            
            int resultLength = lastNegativeIndex - penultimateNegativeIndex + 1;
            int resultArray[resultLength];
            getSlice(enteredArr, length, resultArray, resultLength, penultimateNegativeIndex, lastNegativeIndex);
            
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