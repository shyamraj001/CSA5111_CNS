#include <stdio.h>

int main() {
    unsigned char plaintext[100];
    unsigned char iv, key, feedback, cipher;
    int i, n;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    if (n < 1 || n > 99) {
        printf("Invalid length\n");
        return 1;
    }

    printf("Enter plaintext characters: ");
    for (i = 0; i < n; i++)
        scanf(" %c", &plaintext[i]);

    printf("Enter key (0-255): ");
    scanf("%hhu", &key);

    printf("Enter IV (0-255): ");
    scanf("%hhu", &iv);

    feedback = iv;

    printf("Ciphertext (hex): ");

    for (i = 0; i < n; i++) {
        cipher = plaintext[i] ^ key ^ feedback;
        printf("%02X ", cipher);
        feedback = cipher;
    }

    printf("\n");
    return 0;
}
