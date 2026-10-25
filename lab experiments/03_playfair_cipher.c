#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Educational Playfair encryption. J is merged with I. */
int main(void) {
    char key[100], input[200], text[200], matrix[5][5], pairs[400];
    int used[26] = {0}, n = 0, i, r, c, p = 0;

    printf("Enter key (one word): ");
    if (scanf("%99s", key) != 1) return 1;
    printf("Enter plaintext (one word): ");
    if (scanf("%199s", input) != 1) return 1;

    for (i = 0; key[i]; i++) {
        char ch = (char)toupper((unsigned char)key[i]);
        if (ch == 'J') ch = 'I';
        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            matrix[n / 5][n % 5] = ch;
            used[ch - 'A'] = 1;
            n++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (i == ('J' - 'A')) continue;
        if (!used[i]) {
            matrix[n / 5][n % 5] = (char)('A' + i);
            n++;
        }
    }

    n = 0;
    for (i = 0; input[i]; i++) {
        char ch = (char)toupper((unsigned char)input[i]);
        if (ch == 'J') ch = 'I';
        if (ch >= 'A' && ch <= 'Z') text[n++] = ch;
    }
    text[n] = '\0';

    /* Split into digraphs; insert X between repeated letters and at the end. */
    for (i = 0; i < n;) {
        char a = text[i++];
        char b;
        if (i >= n) b = 'X';
        else if (text[i] == a) b = 'X';
        else b = text[i++];
        pairs[p++] = a;
        pairs[p++] = b;
    }
    pairs[p] = '\0';

    printf("Encrypted text: ");
    for (i = 0; i < p; i += 2) {
        int r1 = -1, c1 = -1, r2 = -1, c2 = -1;
        for (r = 0; r < 5; r++) for (c = 0; c < 5; c++) {
            if (matrix[r][c] == pairs[i]) { r1 = r; c1 = c; }
            if (matrix[r][c] == pairs[i + 1]) { r2 = r; c2 = c; }
        }
        if (r1 == r2) {
            putchar(matrix[r1][(c1 + 1) % 5]);
            putchar(matrix[r2][(c2 + 1) % 5]);
        } else if (c1 == c2) {
            putchar(matrix[(r1 + 1) % 5][c1]);
            putchar(matrix[(r2 + 1) % 5][c2]);
        } else {
            putchar(matrix[r1][c2]);
            putchar(matrix[r2][c1]);
        }
    }
    putchar('\n');
    return 0;
}
