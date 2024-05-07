#include <stdio.h>
#include <math.h>

float myArctan(float x) {
    float arctan_x = x; 
    float term = x;   
    float epsilon = 1e-10;
    int i = 1;
    float divisor = 1.0;
    
    while (fabs(term) >= epsilon) { 
        divisor += 2.0;
        term *= -x * x / divisor; 
        arctan_x += term; 
        i++;
    }

    return arctan_x;
}

int main() {
    float x;
    printf("Nhập giá trị x: ");
    scanf("%f", &x);
    printf("%.2f\n", myArctan(x));
    return 0;
}
