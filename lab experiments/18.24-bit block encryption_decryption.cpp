#include <stdio.h>

int main()
{
    unsigned int plaintext, key, ciphertext, decrypted;

    printf("Enter 24-bit plaintext (hex): ");
    scanf("%x", &plaintext);

    printf("Enter 24-bit key (hex): ");
    scanf("%x", &key);

    plaintext = plaintext & 0xFFFFFF;
    key = key & 0xFFFFFF;

    ciphertext = plaintext ^ key;
    decrypted = ciphertext ^ key;

    printf("\nPlaintext  : %06X", plaintext);
    printf("\nKey        : %06X", key);
    printf("\nCiphertext : %06X", ciphertext);
    printf("\nDecrypted  : %06X\n", decrypted);

    return 0;
}
```

