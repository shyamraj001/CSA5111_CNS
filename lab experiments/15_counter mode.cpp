#include <stdio.h>

int main() {
    unsigned char text[100], key;
    int n, i, counter;

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

    printf("Enter initial counter (0-255): ");
    scanf("%d", &counter);

    if (counter < 0 || counter > 255 ||
        counter + n - 1 > 255) {
        printf("Invalid counter range\n");
        return 1;
    }

    printf("Ciphertext (hex): ");

    for (i = 0; i < n; i++) {
        unsigned char stream =
            (unsigned char)(key ^ (counter + i));

        printf("%02X ", text[i] ^ stream);
    }

    printf("\n");
    return 0;
}
