#include <stdio.h>

int main() {
    int state = 1600;
    int block = 1024;
    int capacity = state - block;

    int rateLanes = block / 64;
    int capacityLanes = capacity / 64;

    printf("SHA-3 State Size: %d bits\n", state);
    printf("Block Size: %d bits\n", block);
    printf("Capacity: %d bits\n", capacity);

    printf("Rate Lanes: %d\n", rateLanes);
    printf("Capacity Lanes: %d\n", capacityLanes);

    printf("\nInitially, all capacity lanes are zero.");
    printf("\nRate lanes receive message data.");

    printf("\nWithout permutation, capacity lanes");
    printf("\nremain zero after every absorption.");

    return 0;
}
