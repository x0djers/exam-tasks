/* 
80. Дана целочисленная последовательность и целое число x. Определить,
    есть ли x среди членов последовательности, и если нет, то найти члены
    последовательности, ближайшие к x сверху и снизу.
*/

#include <stdio.h>

int getSeqLength() {
    int seqLen;
    printf("Введите количество элементов массива:\n");
    scanf("%d", &seqLen);
    
    return seqLen;
}

void getSeqInput(int seqCount, int *arr) {
    printf("Введите элементы последовательности (каждое с новой строки):\n");
    
    for (int iter = 0; iter < seqCount; iter++) {
        scanf("%d", (arr + iter));
    }
}

int getXNumber() {
   int x;
   printf("Введите число X:\n");
   scanf("%d", &x);

   return x;
}

int findIndexes(int *xNum, int *lowerBound, int *upperBound, int *arr, int length) {
    int xIndex = -1;
    for (int iter = 0; iter < length; iter++) {
        if (arr[iter] < *xNum && arr[iter] > arr[*lowerBound]  || arr[*lowerBound] > *xNum) {
            *lowerBound = iter;
        } 
        if (arr[iter] == *xNum) {
            xIndex = iter;
        }
        if (arr[iter] > *xNum && arr[iter] < arr[*upperBound] || arr[*upperBound] < *xNum) {
            *upperBound = iter;
        }
    }
    return xIndex;
}

void printResult(int xNum, int xIndex, int lowerBndIndex, int upperBndIndex, int *arr) {
    if (xIndex == -1) {
        printf("Число %d в ведённом массиве не найдено\nБлижайшие к нему элементы:\n", xNum);
        printf("Снизу:\nИндекс: %d | Число: %d\nСверху:\nИндекс: %d | Число: %d\n", lowerBndIndex, arr[lowerBndIndex], upperBndIndex, arr[upperBndIndex]);
    } else {
       printf("Число %d найдено, его индекс: %d\n", xNum, xIndex);
    }
}

int main() {
    int xNum = getXNumber();
    int arrLength = getSeqLength();
    int enteredSeq[arrLength];
    getSeqInput(arrLength, enteredSeq);

    int lowerBound = 0;
    int upperBound = 0;

    int xIndex = findIndexes(&xNum, &lowerBound, &upperBound, enteredSeq, arrLength);

    printResult(xNum, xIndex, lowerBound, upperBound, enteredSeq);
    return 0;
}