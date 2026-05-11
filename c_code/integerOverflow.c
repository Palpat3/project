#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x = INT_MAX;
    printf("Value of x: %d\n", x);
    int result = x + 1; // This will cause an integer overflow
    printf("Result of x + 1: %d\n", result);
    return 0;
}