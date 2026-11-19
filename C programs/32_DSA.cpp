#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int message = 25;
    int privateKey = 7;
    int publicKey = 11;

    srand(time(NULL));

    int k1 = rand() % 100 + 1;
    int k2 = rand() % 100 + 1;

    int sig1 = (message + privateKey + k1) % 100;
    int sig2 = (message + privateKey + k2) % 100;

    printf("Message: %d\n", message);

    printf("First Random k: %d\n", k1);
    printf("Second Random k: %d\n", k2);

    printf("First Signature: %d\n", sig1);
    printf("Second Signature: %d\n", sig2);

    printf("\nDifferent random values produce");
    printf("\ndifferent signatures.");

    return 0;
}
