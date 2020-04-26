// http://www.c-howto.de/tutorial/arrays-felder/uebungen/

#include <stdio.h>

void printField(int *field);
void changePos(int *field, int *posX, int *posY, char input);

int main() {
    char input;                                      // Das Feld fängt oben links an. Koord. nach rechts und unten aufsteigend. x-Achse rechts, y-Achse unten.
    int field[8][8] = {0}, posX=0, posY=0;         // Pointer field zeigt auf zweidim. Array mit 8x8 Feldern, die mit 0 aufgefüllt werden. Position wird mit (0,0) initialisiert.
    
    field[posX][posY] = 1;                          // Erste Position im field setzen.

    do {
        printField(&field[0][0]);                   // Übergebe printField die Speicheradresse des Pointers field an Stelle (0,0).
        scanf("%c", &input);                        // Warte auf Input.
        changePos(&field[0][0], &posX, &posY, input);   // Nach Input: Übergebe changePos Speicheradressen der field, posX und posY-Pointer sowie den eingegebenen Char.
    } while (input != 'x');                         // Wenn x gedrückt -> Abbrechen

    return 0;
}

void printField(int *field) {
    int x, y;                                   
    for (x=0; x<=7; x++) {                      // Schleife für x-Achse
        for (y=0; y<=7; y++) {                  // Schleife für y-Achse
            printf("%d  ", *(field + y*8 + x)); // Drucke Wert, der in der Speicheradresse *(field + y*8 + x) gespeichert ist. Also 0 oder 1.
        }
        printf("\n");                           // Nach jedem x-Achsen-Durchlauf -> neue Zeile.
    }
}

void changePos(int *field, int *posX, int *posY, char input) {
    *(field + *posX * 8 + *posY) = 0;           // Entfernen der alten Position im field. (War vorher 1.)
    
    switch (input) {                            // Je nach input reagieren.
        case 'a': (*posX)--; break;             // Inkrementiere oder dekrementiere *pos_ je nach input.
        case 'd': (*posX)++; break;
        case 'w': (*posY)--; break;
        case 's': (*posY)++; break;
    }

    if (*posX == 8) {                           // Wenn Zug Grenze überschreitet -> Position an anderes Ende setzen.
        *posX = 0;
    } else if (*posY == 8) {
        *posY = 0;
    } else if (*posX == -1) {
        *posX = 7;
    } else if (*posY == -1) {
        *posY = 7;
    }
    
    printf("New Pos: (%d, %d)\n", *posX, *posY);
    *(field + *posX * 8 + *posY) = 1;           // Neue Position im Field setzen (1 speichern).
}