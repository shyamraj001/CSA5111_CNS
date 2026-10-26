#include <stdio.h>
#include <string.h>

/* Toy XOR demonstration of CBC chaining; NOT real encryption or secure. */
int main(void) {
    unsigned char plaintext[200], iv, previous;
    size_t i, n;

    printf("Enter text (up to 199 characters): ");
    if (!fgets((char *)plaintext, sizeof(plaintext), stdin)) return 1;
    n = strlen((char *)plaintext);
    if (n && plaintext[n - 1] == '\n') plaintext[--n] = '\0';

    printf("Enter one-byte IV (0-255): ");
    {
        int value;
        if (scanf("%d", &value) != 1 || value < 0 || value > 255) return 1;
        iv = (unsigned char)value;
    }

    previous = iv;
    printf("Toy CBC output bytes (hex): ");
    for (i = 0; i < n; i++) {
        unsigned char cipher = plaintext[i] ^ previous;
        printf("%02X ", cipher);
        previous = cipher;
    }
    printf("\nWarning: XOR-only demonstration, not secure CBC encryption.\n");
    return 0;
}
