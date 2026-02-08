#include <stdio.h>
double power(double base, int exp) {
    if (exp == 0) {
        return 1;
    } else if (exp > 0) {
        return base * power(base, exp - 1);
    } else {
        return 1 / power(base, -exp);
    }
}
int main() {
    printf("2^5 = %.0f\n", power(2, 5));
    printf("3^4 = %.0f\n", power(3, 4));
    printf("5^-2 = %.2f\n", power(5, -2));
    return 0;
}
