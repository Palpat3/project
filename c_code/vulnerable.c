#include <string.h>

void vulnerable_c_function(char* buf, const char* input) {
    strcpy(buf, input);  // classic buffer overflow, no bounds checking
}