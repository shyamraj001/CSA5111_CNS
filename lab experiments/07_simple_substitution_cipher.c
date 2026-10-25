#include <stdio.h>
#include <ctype.h>

int main(void) {
    char text[200];
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char substitute[] = "MNBVCXZLKJHGFDSAPOIUYTREWQ";
    int i;

    printf("Enter plaintext: ");
    if (!fgets(text, sizeof(text), stdin)) return 1;

    for (i = 0; text[i]; i++) {
        unsigned char ch = (unsigned char)text[i];
        if (isalpha(ch)) {
            int index = toupper(ch) - 'A';
            char enc = substitute[index];
            text[i] = islower(ch) ? (char)tolower((unsigned char)enc) : enc;
        }
    }
    (void)alphabet;
    printf("Encrypted text: %s", text);
    return 0;
}
