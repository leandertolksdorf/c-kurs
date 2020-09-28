// Felix Suhl, Leander Tolksdorf

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { Add = '+', Sub = '-', Mul = '*', Div = '/' } Operator;

// validate operator
int isOperator(Operator op) {
    return op == Add || op == Sub || op == Mul || op == Div;
}

// calculate integer operation
int calculate(Operator op, int a, int b) {
    switch (op) {
        case Add:
            return a + b;
        case Sub:
            return a - b;
        case Mul:
            return a * b;
        case Div:
            return a / b;
        // shouldn't occur with prior validation
        default:
            return 0;
    }
}

// calculate lines from stream
void processStream(FILE* input) {
    // operands and operator
    int a;
    int b;
    char op;

    // count arguments parsed from line
    int argsParsed;
    // buffer for invalid lines
    char s[256];
    // iterate through lines
    while (1) {
        // parse line
        argsParsed = fscanf(input, "%i %c %i", &a, &op, &b);
        // break on end of file
        if (argsParsed == EOF) {
            break;
        }
        // advance if no arguments parsed (invalid line)
        if (argsParsed == 0) {
            // read line with fgets to advance stream position indicator
            fgets(s, 256, input);
            continue;
        }
        // validate operator and print result
        bool operatorValid = isOperator(op);
        if (operatorValid) {
            int result = calculate(op, a, b);
            printf("%i\n", result);
        } else {
            printf("Wrong operator: %c\n", op);
        }
    }
}

int main(int argc, char const* argv[]) {
    // determine input stream
    FILE* input = (argc > 1) ? fopen(argv[1], "r") : stdin;

    // parse, calculate and print results from all lines in stream
    processStream(input);

    // return
    return 0;
}
