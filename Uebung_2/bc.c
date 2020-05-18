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

    int op1, op2, result, test;
    char op;
    while(1) {
        
	test = scanf("%d %c %d", &op1, &op, &op2);
	if(test != 3){
	    printf("Fehler, falsche Eingabe\n");
	    break;
	}else{
	    
            result = calc(op1, op, op2);
            printf("%d\n", result);
	}
    }
}

int main(int argc, char const *argv[]) {

    FILE *fs;
    int op1, op2, result, test;
    char op;
    

    if(argc != 1) {
        for(int i=1; i < argc; i++) {
            // Get file stream pointer
            fs = fopen(argv[i], "r");
		
            while((test = fscanf(fs, "%d %c %d", &op1, &op, &op2)) != EOF) {
		if(test != 3){
		    printf("Fehler, falsche Werte in Datei\n");
	    	    break; 
		}else{
                    printf("%d %c %d\n", op1, op, op2);
                    result = calc(op1, op, op2);
                    printf("%d\n", result);

		    }
		
            }
        }
	
    }
    else{

        readStdin();
    }
    return 0;
}
