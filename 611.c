#include <stdio.h>

void printnchars(int ch, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", ch);
    }
}

int main() {
    int height;
    printf("Nhập chiều cao của tam giác: ");
    scanf("%d", &height);

    for (int i = 1; i <= height; i++) {
        printnchars('*', i);
        printf("\n");
    }

    return 0;
}
