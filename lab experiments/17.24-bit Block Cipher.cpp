#include <stdio.h>

int main()
{
    unsigned int plaintext, key, ciphertext, decrypted;

    printf("Enter 24-bit plaintext (hex): ");
    scanf("%x", &plaintext);

    printf("Enter 24-bit key (hex): ");
    scanf("%x", &key);

    plaintext &= 0xFFFFFF;
    key &= 0xFFFFFF;

    ciphertext = plaintext ^ key;
    decrypted = ciphertext ^ key;

    printf("Plaintext  : %06X\n", plaintext);
    printf("Ciphertext : %06X\n", ciphertext);
    printf("Decrypted  : %06X\n", decrypted);

    return 0;
}
```

