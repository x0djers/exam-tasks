/*
26. Преобразовать строку, оставляя только один символ в каждой
    последовательности подряд идущих одинаковых символов.
*/

#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 101

int getUserInput(char *str) {

    int status = 0;
    
    printf("Программа принимает только первые 100 символов!\nВведите строку: \n");
    if (fgets(str, MAX_STR_SIZE, stdin) != NULL) {
        status = 1;
        if (str[0] == '\n') {
            status = 0;
        }
    }

    return status;
}

void removeDuplicates(char *startStr, char *resultStr) {

    if (strlen(startStr) == 0) {
        resultStr[0] = '\0';
        return;
    }

    int copyIndex = 1;
    resultStr[0] = startStr[0];

    for (int iter = 1; iter < strlen(startStr); iter++) {
        char lastChar = startStr[iter - 1];
        char currentChar = startStr[iter];
        if (currentChar != lastChar) {
            resultStr[copyIndex] = currentChar;
            copyIndex++;
        }
    }
    resultStr[copyIndex] = '\0';
}

int main() {

    char enteredString[MAX_STR_SIZE];
    char resultStr[MAX_STR_SIZE];

    if (getUserInput(enteredString)) {
        removeDuplicates(enteredString, resultStr);
        printf("Получившаяся строка: %s", resultStr);
    } else {
        printf("Вы ввели пустую строку");;
    }

    return 0;
}
