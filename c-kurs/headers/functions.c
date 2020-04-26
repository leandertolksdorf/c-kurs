#include <stdio.h>
#include "functions.h"

int userInput(){
    int n;
    printf("Enter a number.\n");
    scanf("%d", &n);
    return n;
}

void printEvenOrOdd(int n) {
    if (n % 2 == 0) {
        printf("%d is even.", n);
    } else {
        printf("%d is odd", n);
    }
}