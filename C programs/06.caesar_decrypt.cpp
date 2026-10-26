#include <stdio.h>

int main() {
    char text[200];
    int key, i;

    printf("Enter ciphertext: ");
    scanf("%199s", text);

    printf("Enter key: ");
    scanf("%d", &key);

    key = ((key % 26) + 26) % 26;

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' - key + 26) % 26 + 'a';
        }
    }

    printf("Original plaintext: %s\n", text);

    return 0;
}

