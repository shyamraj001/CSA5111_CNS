#include <stdio.h>
#include <string.h>

#define BLOCK 8

void ECB(char *text, char key)
{
    int i;
    printf("\nECB Encryption: ");
    for(i = 0; i < strlen(text); i++)
        printf("%c", text[i] ^ key);
}

void CBC(char *text, char key, char iv)
{
    int i;
    char prev = iv;

    printf("\nCBC Encryption: ");
    for(i = 0; i < strlen(text); i++)
    {
        char cipher = text[i] ^ prev ^ key;
        printf("%c", cipher);
        prev = cipher;
    }
}

void CFB(char *text, char key, char iv)
{
    int i;
    char prev = iv;

    printf("\nCFB Encryption: ");
    for(i = 0; i < strlen(text); i++)
    {
        char cipher = text[i] ^ prev ^ key;
        printf("%c", cipher);
        prev = cipher;
    }
}

int main()
{
    char text[100], key, iv;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key character: ");
    scanf(" %c", &key);

    printf("Enter IV character: ");
    scanf(" %c", &iv);

    ECB(text, key);
    CBC(text, key, iv);
    CFB(text, key, iv);

    printf("\n");

    return 0;
}
