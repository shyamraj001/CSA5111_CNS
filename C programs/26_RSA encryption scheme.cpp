#include <stdio.h>

int power(int a, int b, int n) {
    int r = 1;
    while (b > 0) {
        if (b % 2) r = (r * a) % n;
        a = (a * a) % n;
        b /= 2;
    }
    return r;
}

int main() {
    int p = 3, q = 11;
    int n = p * q, phi = (p-1)*(q-1);
    int e = 3, d = 7, msg = 5;

    int cipher = power(msg, e, n);
    int plain = power(cipher, d, n);

    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);
    printf("Original Message: %d\n", msg);
    printf("Encrypted Message: %d\n", cipher);
    printf("Decrypted Message: %d\n", plain);

    return 0;
}
