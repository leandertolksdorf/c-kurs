#include <stdio.h>
#include <math.h>

int main() {
    int a = 5;

    printf("Variable a - Speicheradresse: %x\n", &a);
    printf("Variable a - Belegter Speicher: %d Bytes\n", sizeof(a));
    printf("Variable a - Wert: %d\n", a);

    int* pointer_a = &a;

    printf("pointer_a - eigene Speicheradresse: %x\n", &pointer_a);
    printf("pointer_a - zeigt auf Speicheradresse: %x\n", pointer_a);
    printf("pointer_a - Wert: %d\n", *pointer_a);

    scanf("%d", pointer_a);

    printf("Variable a - %d", a);
    
    return 0;
}