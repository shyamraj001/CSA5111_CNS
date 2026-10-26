#include <stdio.h>
#include <ctype.h>

int main(void) {
    char text[200];
    int a, b, c, d, i, n = 0;

    printf("Enter plaintext (letters only): ");
    if (scanf("%199s", text) != 1) return 1;
    printf("Enter 2x2 key matrix (a b c d): ");
    if (scanf("%d%d%d%d", &a, &b, &c, &d) != 4) return 1;

    while (text[n]) {
        text[n] = (char)toupper((unsigned char)text[n]);
        n++;
    }
    if (n % 2) text[n++] = 'X';
    text[n] = '\0';

    printf("Encrypted text: ");
    for (i = 0; i < n; i += 2) {
        int x = text[i] - 'A', y = text[i + 1] - 'A';
        printf("%c%c", (a*x + b*y) % 26 + 'A', (c*x + d*y) % 26 + 'A');
    }
    putchar('\n');
    return 0;
}
