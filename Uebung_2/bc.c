#include <stdio.h>

void main(int argc, char const *argv[]) {
    // operanden = argv[1&3] 
    // operator = argv[2]
    printf("%d: %s %c %s", argc, argv[1], argv[2], argv[3]);
}