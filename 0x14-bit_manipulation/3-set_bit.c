#include <stdio.h>

int set_bit(unsigned long int *n, unsigned int index) {
    // Check if the index is valid
    if (index >= sizeof(unsigned long int) * 8) {
        return -1;  // Error: Index out of range
    }

    // Set the bit at the given index to 1
    *n |= (1UL << index);

    return 1;  // Success
}

int main() {
    unsigned long int num = 42;  // Example number
    unsigned int index_to_set = 3;  // Example index

    // Call the set_bit function
    int result = set_bit(&num, index_to_set);

    // Check the result
    if (result == 1) {
        printf("Bit at index %u set to 1. New value: %lu\n", index_to_set, num);
    } else {
        printf("Error: Index out of range\n");
    }

    return 0;
}
