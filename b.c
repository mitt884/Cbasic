#include <stdio.h>
#include <string.h>

void chuanhoa(char *str) {
    int length = strlen(str);
    int i, j;

    for (i = 0, j = 0; i < length; i++) {
        if (str[i] != ' ' || (i > 0 && str[i - 1] != ' ')) { 
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main() {
    char input[50];
    fgets(input, sizeof(input), stdin);

    chuanhoa(input);
    printf("%s", input);

    return 0;
}