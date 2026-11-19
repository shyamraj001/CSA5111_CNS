#include <stdio.h>

int main() {
    int p[4] = {10, 20, 30, 40};
    int key = 15, iv = 5;
    int ecb[4], cbc[4], cfb[4];

    printf("ECB Mode:\n");
    for (int i = 0; i < 4; i++) {
        ecb[i] = p[i] ^ key;
        printf("%d ", ecb[i]);
    }

    printf("\nCBC Mode:\n");
    int prev = iv;

    for (int i = 0; i < 4; i++) {
        cbc[i] = (p[i] ^ prev) ^ key;
        prev = cbc[i];
        printf("%d ", cbc[i]);
    }

    printf("\nCFB Mode:\n");
    prev = iv;

    for (int i = 0; i < 4; i++) {
        cfb[i] = p[i] ^ (prev ^ key);
        prev = cfb[i];
        printf("%d ", cfb[i]);
    }

    return 0;
}
