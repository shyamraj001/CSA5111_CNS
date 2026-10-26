#include <stdio.h>
#include <ctype.h>

int main(void) {
    char text[200];
    int key, i;

    printf("Enter plaintext: ");
    if (!fgets(text, sizeof(text), stdin)) return 1;
    printf("Enter key: ");
    if (scanf("%d", &key) != 1) return 1;

    key = ((key % 26) + 26) % 26;
    for (i = 0; text[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)text[i];
        if (isupper(ch)) text[i] = (char)((ch - 'A' + key) % 26 + 'A');
        else if (islower(ch)) text[i] = (char)((ch - 'a' + key) % 26 + 'a');
    }
    printf("Encrypted text: %s", text);
    return 0;
}
