/*
    Циклический сдвиг вправо на k бит.
    Напишите программу, которая осуществляет циклический
    сдвиг вправо битов числа N на k позиций.
*/

#include <stdio.h>
#include <stdint.h>

#define NUMBER_FORMAT int32_t

NUMBER_FORMAT getInputNumber(char* prompt) {
    int number = 0;

    printf("%s", prompt);
    scanf("%d", &number);

    return number;
}

void printBinary(const NUMBER_FORMAT number) {
    const NUMBER_FORMAT numberSize = sizeof(number) * 8;
    for (NUMBER_FORMAT i = numberSize - 1; i >= 0; i--) {
        printf("%d", (number >> i) & 1);
    }
}

NUMBER_FORMAT cycleShiftRightNumber(const NUMBER_FORMAT number,
                                    NUMBER_FORMAT countOfShifts) {
    const NUMBER_FORMAT numberSize = sizeof(number) * 8;

    countOfShifts = countOfShifts % numberSize;

    return number >> countOfShifts | number << (numberSize - countOfShifts);
}

int main() {
    NUMBER_FORMAT enteredNumber = getInputNumber("Введите целое число: ");
    NUMBER_FORMAT countOfShifts = getInputNumber("Введите количество сдвигов: ");

    NUMBER_FORMAT resultNumber = cycleShiftRightNumber(enteredNumber, countOfShifts);

    printBinary(resultNumber);
}

