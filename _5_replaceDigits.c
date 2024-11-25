/*
5. Преобразовать строку, заменяя каждую цифру
   соответствующим ей числом пробелов.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ENTERED_STR_SIZE 101
#define MAX_CHANGED_STR_SIZE 901

void getUserInput(char *str) {
    
    printf("Программа принимает только первые 100 символов!\nВведите строку: \n");
    scanf("%100s", str);
}

void replaceDigits(char *startStr, char *resultStr) {

    int copyIndex = 0;

    for (int iter = 0; iter < strlen(startStr); iter++) {
        if (isdigit(startStr[iter])) {
            int spaceNum = (int)startStr[iter] - 48;
            for (int _ = 0; _ < spaceNum; _++) {
                resultStr[copyIndex] = ' ';
                copyIndex++;
            }
        } else {
            resultStr[copyIndex] = startStr[iter];
            copyIndex++;
        }
    }

    resultStr[copyIndex] = '\0';
}

int main() {

    char enteredString[MAX_ENTERED_STR_SIZE];
    char resultStr[MAX_CHANGED_STR_SIZE];

    getUserInput(enteredString);

    replaceDigits(enteredString, resultStr);
    printf("Получившаяся строка: %s", resultStr);

    return 0;
}