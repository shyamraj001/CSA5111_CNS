#include <stdio.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

int main(void) {
    char text[200];
    int a, b, i;

    printf("Enter plaintext: ");
    if (!fgets(text, sizeof(text), stdin)) return 1;
    printf("Enter keys a and b (gcd(a,26) must be 1): ");
    if (scanf("%d%d", &a, &b) != 2) return 1;
    a = ((a % 26) + 26) % 26;
    b = ((b % 26) + 26) % 26;
    if (gcd(a, 26) != 1) {
        printf("Invalid key: a must be relatively prime to 26.\n");
        return 1;
    }

    for (i = 0; text[i]; i++) {
        unsigned char ch = (unsigned char)text[i];
        if (isupper(ch)) text[i] = (char)((a * (ch - 'A') + b) % 26 + 'A');
        else if (islower(ch)) text[i] = (char)((a * (ch - 'a') + b) % 26 + 'a');
    }
    printf("Encrypted text: %s", text);
    return 0;
}
