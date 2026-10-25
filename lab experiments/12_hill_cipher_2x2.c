#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char text[200], out[200];
    int a, b, c, d, i, n = 0;

    printf("Enter plaintext (letters only): ");
    if (scanf("%199s", text) != 1) return 1;
    printf("Enter 2x2 key matrix (a b c d): ");
    if (scanf("%d%d%d%d", &a, &b, &c, &d) != 4) return 1;

    for (i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) {
            out[n++] = (char)(toupper((unsigned char)text[i]));
        }
    }
    if (n % 2) out[n++] = 'X';
    out[n] = '\0';

    printf("Encrypted text: ");
    for (i = 0; i < n; i += 2) {
        int x = out[i] - 'A', y = out[i + 1] - 'A';
        putchar((a * x + b * y) % 26 + 'A');
        putchar((c * x + d * y) % 26 + 'A');
    }
    putchar('\n');
    return 0;
}
