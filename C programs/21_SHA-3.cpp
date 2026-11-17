#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    unsigned long hash = 0;

    printf("Enter message: ");
    gets(msg);

    for(int i = 0; msg[i] != '\0'; i++)
        hash = hash * 31 + msg[i];

    printf("Pseudo SHA-3 Hash: %lu\n", hash);

    return 0;
}
