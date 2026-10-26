#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char text[200], key[100];
    int i, j = 0, keylen;

    printf("Enter plaintext: ");
    if (!fgets(text, sizeof(text), stdin)) return 1;
    printf("Enter key (letters only): ");
    if (scanf("%99s", key) != 1) return 1;
    keylen = (int)strlen(key);
    if (keylen == 0) return 1;

    for (i = 0; text[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)text[i];
        if (isalpha(ch)) {
            int base = isupper(ch) ? 'A' : 'a';
            int shift = toupper((unsigned char)key[j % keylen]) - 'A';
            if (shift < 0 || shift > 25) {
                printf("\nKey must contain letters only.\n");
                return 1;
            }
            text[i] = (char)((ch - base + shift) % 26 + base);
            j++;
        }
    }
    printf("Encrypted text: %s", text);
    return 0;
}
