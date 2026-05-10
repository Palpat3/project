#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    *p = 42;
    printf("Value before free: %d\n", *p);
    free(p);
    printf("Value after free: %d\n", *p); // Use after free
    return 0;
}