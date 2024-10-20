#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(){
    // int a[2][3][2] = {{{1, 2},{3, 4},{5, 6}},{{7, 8},{9, 10},{11, 12}}}; //arrays, rows, columns
    // printf("%d %d\n", a[0][2][1], a[1][2][0]);

    int hasUpper = 0, hasNumber = 0, hasSpecial = 0, len = 0;
    char input[25];
    printf("Input a password: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; //removing the \n and replacing it with end of string
    len = strlen(input);
    for(int i = 0; i < len; i++){
        if(islower(input[i])){
            continue;
        }
        if(isupper(input[i])){
            hasUpper++;
            continue;
        }
        if(isdigit(input[i])){
            hasNumber++;
            continue;
        }
        hasSpecial++; //could use alnum() to check if it's a alpha-numeric character (returns false for special char) (#include <stdlib.h>)
    }
    if(len > 6 && hasUpper > 0 && hasNumber > 0 && hasSpecial > 0){
        printf("Your password is good!\n"); 
    }
    else{
        printf("Your password is bad!\n");
    }
}