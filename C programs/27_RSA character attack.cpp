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
    int e = 7, n = 187;
    int i, c;

    printf("Character\tEncrypted\n");

    for (i = 0; i < 26; i++) {
        c = power(i, e, n);
        printf("%c\t\t%d\n", 'A' + i, c);
    }

    printf("\nAttack: Compare ciphertext values with");
    printf("\nthe 26 possible encrypted characters.");

    return 0;
}
