// http://www.c-howto.de/tutorial/arrays-felder/uebungen/

#include <stdio.h>

int noten[10];
float durchschnitt;

void main() {
    int i, note;
    int summe = 0;

    for (i=0; i <= 10; i++) {
        printf("\nNote eingeben");
        scanf("%d", &note);
        noten[i] = note;
    }
    for (i=0; i <= 10; i++) {
        summe += noten[i];
    }
    durchschnitt = summe / 10;
    printf("Der Durchschnitt ist: %f", durchschnitt);
}