#include <stdio.h>

int main() {
    int a, b;

    printf("Zahl eingeben");
    scanf("%d", &a);

    a = --a;
    
    printf("%d", a);

    b = 1 - a;
    printf("Ergebnis: %d", b);
    return 0;
}