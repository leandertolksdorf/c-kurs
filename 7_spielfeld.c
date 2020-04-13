// http://www.c-howto.de/tutorial/arrays-felder/uebungen/

#include <stdio.h>

void playerInput();

void main() {
    int field[8][8] = {0}, posX = 0, posY = 0;

    field[0][0] = 1; //Setze Spieler auf 0,0

    playerInput();

}

void playerInput() {
    char pressed;
    while (pressed != 'x') {
        printf("Waiting for user input");
        scanf("%c", &pressed);
        printf("%c", pressed);
    }
}

void move(int *field, int *posX, int *posY, char zug) {
    switch (zug) {
        case 'w': field[*posX][posY] = 0; field
    }
}