#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

    int jahre;

    printf("Alter eingeben:");
    scanf("%d", &jahre);

    int tage = jahre * 365;
    int stunden = tage * 24;
    int minuten = stunden * 60;
    int sekunden = minuten * 60;

    printf("Du lebst seit %d Tagen, %d Stunden, %d Minuten oder %d Sekunden", tage, stunden, minuten, sekunden);

    return 0;
}