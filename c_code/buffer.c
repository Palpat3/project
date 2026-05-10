#include <stdio.h>
#include <string.h>

int main() {
    int secret = 420;
    char buffer[8];

    printf("Before buffer overflow: secret = %d\n", secret);
    strcpy(buffer, "This is a long string that will overflow the buffer");
    printf("After buffer overflow: secret = %d\n", secret);
    printf("Buffer content: %s\n", buffer);
    return 0;
}