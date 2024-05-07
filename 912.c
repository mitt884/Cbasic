#include <stdio.h>

double celsius(double f) {
    return (5.0 / 9.0) * (f - 32.0);
}

int main() {
    printf("   Độ F     |    Độ C\n");
    printf("-----------------------\n");
    for (int f = 1; f <= 20; f++) {
        double c = celsius(f);
        printf("%8d     |  %8.2f\n", f, c);
    }
    return 0;
}
