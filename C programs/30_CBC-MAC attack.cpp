#include <stdio.h>

int main() {
    int X = 10;
    int T = 25;

    int secondBlock = X ^ T;

    printf("Original Message X: %d\n", X);
    printf("CBC-MAC of X (T): %d\n", T);

    printf("Second Block (X XOR T): %d\n",
           secondBlock);

    printf("\nForged Message: X || (X XOR T)");

    printf("\nThe forged two-block message");
    printf("\nproduces the same MAC under the");
    printf("\nassumed CBC-MAC construction.");

    return 0;
}
