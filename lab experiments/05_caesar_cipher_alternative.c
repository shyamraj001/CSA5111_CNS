#include <stdio.h>

int main(void) {
    char text[200];
    int key, i;

    printf("Enter plaintext (no spaces): ");
    if (scanf("%199s", text) != 1) return 1;
    printf("Enter key: ");
    if (scanf("%d", &key) != 1) return 1;
    key = ((key % 26) + 26) % 26;

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = (char)((text[i] - 'A' + key) % 26 + 'A');
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = (char)((text[i] - 'a' + key) % 26 + 'a');
    }
    printf("Encrypted text: %s\n", text);
    return 0;
}
