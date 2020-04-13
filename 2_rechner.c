#include <stdio.h>

int main() {
    // Definieren der Variablen
    int op1, op2, result;

    // Input
    printf("Taschenrechner\n");
    printf("Zahl 1:");
    scanf("%d", &op1);
    printf("Zahl 2:");
    scanf("%d", &op2);

    // Berechnung und Ausgabe
    result = op1 + op2;
    printf("%d + %d = %d", op1, op2, result);

    return result;
}