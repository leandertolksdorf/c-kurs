#include <stdio.h>
#include <stdbool.h>

int waehleGetraenk();
int waehleAnzahl();
float holePreis(int);
void bezahlen(float);
void ausgabe(int, int);
bool pruefeMuenze(float);

void main() {

    int getraenk, anzahl;
    float preis, zuZahlen;

    getraenk = waehleGetraenk();
    anzahl = waehleAnzahl();
    preis = holePreis(getraenk);
    zuZahlen = preis * anzahl;
    bezahlen(zuZahlen);
    ausgabe(getraenk, anzahl);
}

int waehleGetraenk() {
    int getraenk;
    printf("\nWähle Getränk:\n1) Wasser (0,5)\n2)Cola (1)\n3) Bier(2)");
    scanf("\n%d", &getraenk);
    return getraenk;
}

int waehleAnzahl() {
    int anzahl;
    printf("\nWähle die Anzahl:");
    scanf("\n%d", &anzahl);
    return anzahl;
}

float holePreis(int getraenk) {
    switch (getraenk) {
        case 1: return 0.5;
        case 2: return 1;
        case 3: return 2;
    }
}

void bezahlen(float preis) {
    float gezahlt = 0, einwurf;
    while (gezahlt < preis) {
        einwurf = 0;
        printf("\nNoch zu zahlen: %f", preis - gezahlt);
        scanf("%f", &einwurf);
        if (pruefeMuenze(einwurf)) {
            gezahlt += einwurf;
        } else {
            printf("Diese Münze gibt es nicht.");
            continue;
        }
    }
    printf("Bezahlt. Rückgeld: %f", gezahlt - preis );
}

void ausgabe(int getraenk, int anzahl) {
    switch (getraenk) {
        case 1: printf("\nAusgabe: %dx Wasser", anzahl); break;
        case 2: printf("\nAusgabe: %dx Cola", anzahl); break;
        case 3: printf("\nAusgabe: %dx Bier", anzahl); break;
    }
}

bool pruefeMuenze(float muenze) {
    float arr[] = {0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 1, 2};
    int i;
    for (i=0; i <= 7; i++) {
        if (muenze == arr[i]) {
            return true;
        }
    }
    return false;
}