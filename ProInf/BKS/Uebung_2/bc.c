#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

// validate operator
int validateOperator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

// calculate integer operation
int calculate(char op, int a, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            // default case shouldn't occur with prior validation
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
        // end of file
        if (argsParsed == EOF) {
            break;
        }
        // no arguments parsed from line (invalid)
        if (argsParsed == 0) {
            // read line with fgets to advance stdin position indicator
            fgets(s, 256, input);
            continue;
        }
        // calculate result
        if (validateOperator(op)) {
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
