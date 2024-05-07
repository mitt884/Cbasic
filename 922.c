#include <stdio.h>
#include <math.h>

float mySinh(float x) {
    float sinh_x = x; 
    float term = x;   
    float eps = 1e-10;
    int i = 1;
    
    while (fabs(term) >= eps) { 
        term *= x * x / ((2 * i) * (2 * i + 1)); 
        sinh_x += term; 
        i++;
    }

    return sinh_x;
}

int main() {
    float x;
    scanf("%f", &x);
    float m = mySinh(x);
    printf("%.2f\n", m);
    return 0;
}
