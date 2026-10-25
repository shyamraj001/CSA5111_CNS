#include <stdio.h>
#include <ctype.h>

int main(void) {
    char text[200];
    const char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;

    printf("Enter plaintext: ");
    if (!fgets(text, sizeof(text), stdin)) return 1;

    for (i = 0; text[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)text[i];
        if (isalpha(ch)) {
            int index = toupper(ch) - 'A';
            text[i] = key[index];
        }
    }
    printf("Encrypted text: %s", text);
    return 0;
}
