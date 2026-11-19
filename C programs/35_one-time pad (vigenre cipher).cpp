#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char text[100];
    int key[100], i, n;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    n = 0;
    while (text[n] != '\0')
        n++;

    srand(time(NULL));

    printf("\nRandom Key: ");
    for (i = 0; i < n; i++) {
        key[i] = rand() % 26;
        printf("%d ", key[i]);
    }

    printf("\nEncrypted Text: ");

    for (i = 0; i < n; i++) {
        char c = text[i];

        if (c >= 'a' && c <= 'z')
            c -= 32;

        if (c >= 'A' && c <= 'Z')
            printf("%c", ((c-'A'+key[i])%26)+'A');
        else
            printf("%c", c);
    }

    return 0;
}
