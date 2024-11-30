/*
30. Определить, входит ли цифра M в запись числа N типа uint64_t.
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

int getDigitCount(uint64_t number, int digit) {
    int count = 0;
    while (number > 0) {
        if (number % 10 == digit) {
            count++;
        }
        number /= 10;
    }
    return count;
}

void getUserInput(uint64_t *number, int *digit) {
    printf("Введте беззнаковое число N: ");
    scanf("%lu", number);
    printf("Введте цифру M: ");
    scanf("%d", digit);
}

int main() {
    uint64_t number;
    int m;
    getUserInput(&number, &m);
    if (m < 0 || m > 9) {
        printf("Введенное число не является цифрой\n");
        return 1;
    } else {
        int count = getDigitCount(number, m);
        printf("Цифра %d встречается в числе %lu %d раз\n", m, number, count);
    }
    return 0;
}