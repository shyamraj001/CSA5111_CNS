#include <stdio.h>
#include <string.h>

int main() {
    char text[100], result[100];
    int key[10], i, j, k = 0, len, cols;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (cols < 1 || cols > 10) {
        printf("Invalid number of columns\n");
        return 1;
    }

    printf("Enter column order: ");
    for (i = 0; i < cols; i++)
        scanf("%d", &key[i]);

    for (i = 0; i < cols; i++) {
        if (key[i] < 1 || key[i] > cols) {
            printf("Invalid column order\n");
            return 1;
        }

        for (j = 0; j < i; j++) {
            if (key[i] == key[j]) {
                printf("Duplicate column order\n");
                return 1;
            }
        }
    }

    len = strlen(text);

    for (i = 0; i < cols; i++) {
        for (j = 0; j < cols; j++) {
            if (key[j] == i + 1) {
                int pos;
                for (pos = j; pos < len; pos += cols)
                    result[k++] = text[pos];
            }
        }
    }

    result[k] = '\0';
    printf("Ciphertext: %s\n", result);

    return 0;
}
