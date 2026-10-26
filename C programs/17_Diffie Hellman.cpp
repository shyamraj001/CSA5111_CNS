#include <stdio.h>

long long power(long long a, long long b, long long p) {
    long long result = 1;
    a %= p;

    while (b > 0) {
        if (b % 2)
            result = result * a % p;

        a = a * a % p;
        b /= 2;
    }

    return result;
}

int main() {
    long long p = 23, g = 5;
    long long a, b, A, B, keyA, keyB;

    printf("Enter private key of Alice: ");
    scanf("%lld", &a);

    printf("Enter private key of Bob: ");
    scanf("%lld", &b);

    if (a < 1 || a >= p - 1 || b < 1 || b >= p - 1) {
        printf("Private keys must be between 1 and 21\n");
        return 1;
    }

    A = power(g, a, p);
    B = power(g, b, p);

    keyA = power(B, a, p);
    keyB = power(A, b, p);

    printf("Alice's public key: %lld\n", A);
    printf("Bob's public key: %lld\n", B);
    printf("Alice's shared key: %lld\n", keyA);
    printf("Bob's shared key: %lld\n", keyB);

    return 0;
}
