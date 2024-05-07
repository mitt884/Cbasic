#include <stdio.h>
#include <math.h>

float myCosh(float x) {
    float cosh_x = 1; 
    float term = 1;   
    float epsilon = 1e-10;
    int i = 1;
    
    while (fabs(term) >= epsilon) { 
        term *= x * x / ((2 * i - 1) * (2 * i)); 
        cosh_x += term; 
        i++;
    }

    return cosh_x;
}

int main() {
    float x;
    scanf("%f", &x);
    printf("%.2f\n", myCosh(x));
    return 0;
}
