#include <stdio.h>

float tinhTong(int n) {
    float tong = 0.0;
    for (int i = 1; i <= n; i++) {
        tong += 1.0 / i;
    }
    return tong;
}

int main() {
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    float m = tinhTong(n);
    printf("%.2f", m);
    return 0;
}
