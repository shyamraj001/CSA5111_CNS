#include <stdio.h>
#include <string.h>

/* Toy XOR demonstration of ECB-like independent blocks; NOT real encryption. */
int main(void) {
    unsigned char text[200];
    int key, i;
    size_t n;

    printf("Enter text (up to 199 characters): ");
    if (!fgets((char *)text, sizeof(text), stdin)) return 1;
    n = strlen((char *)text);
    if (n && text[n - 1] == '\n') text[--n] = '\0';

    printf("Enter one-byte key (0-255): ");
    if (scanf("%d", &key) != 1 || key < 0 || key > 255) return 1;

    printf("Toy ECB output bytes (hex): ");
    for (i = 0; i < (int)n; i++) printf("%02X ", text[i] ^ (unsigned char)key);
    printf("\nWarning: XOR-only demonstration, not secure ECB encryption.\n");
    return 0;
}
