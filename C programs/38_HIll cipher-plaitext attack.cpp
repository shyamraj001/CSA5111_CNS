#include <stdio.h>

int main() {
    int key[2][2] = {{3, 3}, {2, 5}};
    int p[2], c[2];

    printf("Enter two plaintext numbers (0-25): ");
    scanf("%d%d", &p[0], &p[1]);

    for (int i = 0; i < 2; i++) {
        c[i] = 0;

        for (int j = 0; j < 2; j++)
            c[i] += key[i][j] * p[j];

        c[i] %= 26;
    }

    printf("Encrypted Values: %d %d\n", c[0], c[1]);

    printf("\nKnown Plaintext: %d %d", p[0], p[1]);
    printf("\nKnown Ciphertext: %d %d", c[0], c[1]);

    printf("\nThese pairs can be used to");
    printf("\nrecover the key matrix.");

    return 0;
}
