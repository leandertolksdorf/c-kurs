#include <stdio.h>
//TEST
int main() {
    int test = 420;
    int userInput;
    printf("Eingabe:");
    scanf("%d", &userInput);
    
    int result = test + userInput;
    printf("420 + %d ist: %d", userInput, result);
    
    
}
