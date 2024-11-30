/*
3.  Удалить из строки все символы, не являющиеся буквами, а
    прописные буквы заменить строчными.
*/

#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 1001

void getUserInput(char *str) {
    printf("Программа принимает только первые %d символов!\nВведите строку: ", MAX_STRING_SIZE - 1);
    scanf("%s", str);
}

void clearString(char *inString, char *resultString) {
    int copyIndex = 0;
    for (int i = 0; i < strlen(inString); i++) {
        if ('a' <= inString[i] && inString[i] <= 'z') {
            resultString[copyIndex] = inString[i];
            copyIndex++;
        } else if ('A' <= inString[i] && inString[i] <= 'Z') {
            resultString[copyIndex] = inString[i] + ('a' - 'A');
            copyIndex++;
        }
    }
    resultString[copyIndex] = '\0';
}

int main() {
    char inString[MAX_STRING_SIZE];
    char resultString[MAX_STRING_SIZE];
    getUserInput(inString);
    clearString(inString, resultString);
    printf("Результат: %s\n", resultString);
    return 0;
}