#include <stdio.h>
#include <string.h>

int main() {
    char buffer[8];
    int secret = 420;
    

    printf("Before buffer overflow: secret = %d\n", secret);
    strcpy(buffer, "This is a long string that will overflow the buffer");
    printf("After buffer overflow: secret = %d\n", secret);
    printf("Buffer content: %s\n", buffer);
    return 0;
}