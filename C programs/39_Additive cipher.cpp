#include <stdio.h>

int main() {
    char text[1000];

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    printf("\nPossible Plaintexts:\n");

    for (int key = 0; key < 26; key++) {
        printf("Key %d: ", key);

        for (int i = 0; text[i]; i++) {
            char c = text[i];

            if (c >= 'A' && c <= 'Z')
                printf("%c", (c-'A'-key+26)%26+'A');
            else if (c >= 'a' && c <= 'z')
                printf("%c", (c-'a'-key+26)%26+'a');
            else
                printf("%c", c);
        }

        printf("\n");
    }

    return 0;
}
