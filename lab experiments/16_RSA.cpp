#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long power(long long a, long long b, long long m) {
    long long result = 1;
    a %= m;

    while (b > 0) {
        if (b % 2)
            result = result * a % m;

        a = a * a % m;
        b /= 2;
    }

    return result;
}

int main() {
    long long p = 3, q = 11;
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    long long e = 3, d = 7, msg, cipher, decrypted;

    if (gcd(e, phi) != 1) {
        printf("Invalid public exponent\n");
        return 1;
    }

    printf("Enter message number (0-32): ");
    scanf("%lld", &msg);

    if (msg < 0 || msg >= n) {
        printf("Message must be between 0 and 32\n");
        return 1;
    }

    cipher = power(msg, e, n);
    decrypted = power(cipher, d, n);

    printf("Public key: (%lld, %lld)\n", e, n);
    printf("Private key: (%lld, %lld)\n", d, n);
    printf("Encrypted message: %lld\n", cipher);
    printf("Decrypted message: %lld\n", decrypted);

    return 0;
}
