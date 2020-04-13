#include <stdio.h>

void main() {
    int gewicht;

    printf("Gewicht eingeben");
    scanf("%d", &gewicht);

    if (gewicht > 100)
    {
        printf("Willkommen im Club 100");
    } else if (gewicht == 100) {
        printf("Gerade so.");
    } else {
        printf("Das reicht noch nicht");
    }
    
    return;
    
}