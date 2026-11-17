#include <stdio.h>

unsigned char encrypt(unsigned char data, unsigned char key) {
    return data ^ key;
}

unsigned char decrypt(unsigned char data, unsigned char key) {
    return data ^ key;
}

int main() {
    unsigned char plain = 'A';
    unsigned char key = 0x5A;

    unsigned char cipher = encrypt(plain, key);

    printf("Encrypted: %02X\n", cipher);

    unsigned char decrypted = decrypt(cipher, key);

    printf("Decrypted: %c\n", decrypted);

    return 0;
}
