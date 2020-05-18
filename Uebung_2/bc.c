#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 16

int calc(int op1, char op, int op2) {
    int result;
    switch(op){
            case '+': result = op1 + op2; break;
            case '-': result = op1 - op2; break;
            case '*': result = op1 * op2; break;
            case '/': result = op1 / op2; break;
            default:  result = -1; printf("Wrong operator: %c\n", op); break;
        }
    return result;
}

void readStdin() {
    int op1, op2, result;
    char op;
    while(1) {
        scanf("%d %c %d", &op1, &op, &op2);
        result = calc(op1, op, op2);
        printf("%d", result);
    }
}

int main(int argc, char const *argv[]) {

    FILE *fs;
    int op1, op2, result;
    char op;

    if(argc != 1) {
        for(int i=1; i < argc; i++) {
            // Get file stream pointer
            fs = fopen(argv[i], "r");
            while(fscanf(fs, "%d %c %d", &op1, &op, &op2) != EOF) {
                printf("%d %c %d\n", op1, op, op2);
                result = calc(op1, op, op2);
                printf("%d\n", result);
            }
        }
    }

    readStdin();

    return 0;
}