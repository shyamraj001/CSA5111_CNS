#include <stdio.h>
#include <string.h>

void xorBlock(char *a, char *b, char *res) {
    for(int i=0;i<8;i++)
        res[i] = a[i] ^ b[i];
}

int main() {
    char key[9] = "SECURITY";
    char msg[17] = "HELLOWORLD123456";

    char mac[9] = {0};

    for(int i=0;i<16;i+=8) {
        xorBlock(mac, msg+i, mac);

        for(int j=0;j<8;j++)
            mac[j] ^= key[j];
    }

    printf("CBC-MAC: ");

    for(int i=0;i<8;i++)
        printf("%02X", (unsigned char)mac[i]);

    printf("\n");

    return 0;
}
