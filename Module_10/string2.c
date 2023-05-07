#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Task2. Build the toLower() function here.
void toLower(char a[]){
    for(int i=0; i<strlen(a); i++){
        a[i] = tolower(a[i]);
    }
}

int main(){
    char input[100];
    // Task 1. Read in user input to the char array input.
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character
    
    // Task 3. Call the toLower function.
    toLower(input);
    printf("%s\n", input);
    return 0;
}
