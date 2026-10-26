#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int iv, key, i;
    unsigned char previous, cipher;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    printf("Enter key (0-255): ");
    scanf("%d", &key);

    printf("Enter IV (0-255): ");
    scanf("%d", &iv);

    if (key < 0 || key > 255 || iv < 0 || iv > 255) {
        printf("Invalid key or IV\n");
        return 1;
    }

    previous = (unsigned char)iv;

    printf("Ciphertext (hex): ");

    for (i = 0; text[i] != '\0'; i++) {
        cipher = ((unsigned char)text[i] ^ previous)
                 ^ (unsigned char)key;

        printf("%02X ", cipher);
        previous = cipher;
    }

    printf("\n");
    return 0;
}
