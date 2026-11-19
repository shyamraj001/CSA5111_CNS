#include <stdio.h>
#include <stdint.h>

uint64_t leftShift(uint64_t x) {
    return x << 1;
}

int main() {
    uint64_t L = 0x123456789ABCDEF0ULL;

    uint64_t K1 = leftShift(L);

    if (L >> 63)
        K1 ^= 0x1B;

    uint64_t K2 = leftShift(K1);

    if (K1 >> 63)
        K2 ^= 0x1B;

    printf("L  = %llX\n", (unsigned long long)L);
    printf("K1 = %llX\n", (unsigned long long)K1);
    printf("K2 = %llX\n", (unsigned long long)K2);

    printf("\n64-bit Rb constant: 0x1B");
    printf("\n128-bit Rb constant: 0x87");

    return 0;
}
