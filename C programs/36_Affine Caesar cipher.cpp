#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    if (gcd(a, 26) != 1) {
        printf("Invalid key! a must be coprime to 26.");
        return 0;
    }

    printf("Encrypted Text: ");

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] -= 32;

        if (text[i] >= 'A' && text[i] <= 'Z') {
            int p = text[i] - 'A';
            printf("%c", ((a*p+b)%26)+'A');
        }
    }

    return 0;
}
