#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char key[100], matrix[5][5];
    int used[26] = {0}, n = 0, i, r, c;

    printf("Enter key (one word): ");
    if (scanf("%99s", key) != 1) return 1;
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
        if (!used[i]) { matrix[n / 5][n % 5] = (char)('A' + i); n++; }
    }
    printf("Playfair matrix:\n");
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) printf("%c ", matrix[r][c]);
        putchar('\n');
    }
    return 0;
}
