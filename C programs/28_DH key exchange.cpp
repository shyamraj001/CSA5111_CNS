#include <stdio.h>

int power(int a, int b, int q) {
    int r = 1;
    while (b > 0) {
        if (b % 2) r = (r * a) % q;
        a = (a * a) % q;
        b /= 2;
    }
    return r;
}

int main() {
    int q = 23, a = 5;
    int x = 6, y = 15;

    int A = power(a, x, q);
    int B = power(a, y, q);

    int keyA = power(B, x, q);
    int keyB = power(A, y, q);

    printf("Alice Public Value: %d\n", A);
    printf("Bob Public Value: %d\n", B);

    printf("Alice Secret Key: %d\n", keyA);
    printf("Bob Secret Key: %d\n", keyB);

    if (keyA == keyB)
        printf("Shared Key Established Successfully");

    return 0;
}
