#include <stdio.h>

int main() {
    unsigned char text[100], iv, key, stream;
    int n, i;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    if (n < 1 || n > 99) {
        printf("Invalid length\n");
        return 1;
    }

    printf("Enter plaintext characters: ");
    for (i = 0; i < n; i++)
        scanf(" %c", &text[i]);

    printf("Enter key (0-255): ");
    scanf("%hhu", &key);

    printf("Enter IV (0-255): ");
    scanf("%hhu", &iv);

    stream = iv;

    printf("Ciphertext (hex): ");

    for (i = 0; i < n; i++) {
        stream = stream ^ key;
        printf("%02X ", text[i] ^ stream);
    }

    printf("\n");
    return 0;
}
