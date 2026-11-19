#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    char freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0};
    int order[26];

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    // Count letter frequencies
    for (int i = 0; text[i]; i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            count[text[i] - 'a']++;

        else if (text[i] >= 'A' && text[i] <= 'Z')
            count[text[i] - 'A']++;
    }

    // Initialize alphabet order
    for (int i = 0; i < 26; i++)
        order[i] = i;

    // Sort letters by frequency
    for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (count[order[j]] > count[order[i]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    // Generate top 10 possible plaintexts
    printf("\nPossible Plaintexts:\n");

    for (int k = 0; k < 10; k++) {
        printf("Attempt %d: ", k + 1);

        for (int i = 0; text[i]; i++) {
            char c = text[i];

            if (c >= 'a' && c <= 'z') {
                int rank = 0;

                while (rank < 26 && order[rank] != c - 'a')
                    rank++;

                printf("%c", freq[(rank + k) % 26] + 32);
            }
            else if (c >= 'A' && c <= 'Z') {
                int rank = 0;

                while (rank < 26 && order[rank] != c - 'A')
                    rank++;

                printf("%c", freq[(rank + k) % 26]);
            }
            else {
                printf("%c", c);
            }
        }

        printf("\n");
    }

    return 0;
}
