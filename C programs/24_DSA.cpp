#include <stdio.h>
#include <math.h>

long long modpow(long long a, long long b, long long mod) {
    long long result = 1;

    while(b > 0) {
        if(b % 2)
            result = (result * a) % mod;

        a = (a * a) % mod;
        b /= 2;
    }

    return result;
}

int main() {
    long long p = 23;
    long long q = 11;
    long long g = 2;

    long long x = 6;   // private key
    long long y = modpow(g, x, p);

    printf("Public Key (y) = %lld\n", y);
    printf("Private Key (x) = %lld\n", x);

    long long k = 3;
    long long r = modpow(g, k, p) % q;

    long long h = 9;

    long long s = ((h + x * r) / k) % q;

    printf("Signature (r,s) = (%lld,%lld)\n", r, s);

    return 0;
}
