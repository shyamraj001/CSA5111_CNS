#include <stdio.h>
#include <string.h>

int main() {
    char key[] = "SECRETKEY";
    char msg[] = "HELLO";

    unsigned char mac = 0;

    for(int i=0; msg[i]!='\0'; i++)
        mac ^= msg[i];

    for(int i=0; key[i]!='\0'; i++)
        mac ^= key[i];

    printf("Simplified CMAC = %02X\n", mac);

    return 0;
}
