#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* local_pointer() {
    int x = 10;
    printf("Inside function: x = %d, address = %p\n", x, (void*)&x);
    return &x; // Returning address of a local variable (dangling pointer)
}

int main() {
    int* dangling = local_pointer();
    printf("In main: dangling pointer address = %p\n", (void*)dangling);

    printf("Now trying to read value: %d\n", *dangling);

    return 0;
}

//Windows nulls out the returned pointer, it detects the dangling pointer and prevents access, while Linux does not, allowing access to potentially invalid memory.