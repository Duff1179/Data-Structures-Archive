#include <stdio.h>
#include <limits.h>

void main(){
    int n = -1, ncheck = -1, input = -1, incheck = -1, magic = 1, sel = 1;
    printf("What matrix size do you want: ");
    ncheck = scanf("%d", &n);
    if(ncheck != 1  || n < 3){
        printf("Invalid input!\nQuitting program.\n");
        return;
    }
    int in[n][n];
    int rowsum[n];
    int colsum[n];
    int diagsum[2] = {0};
    for(int i = 0; i < n; i++){
        rowsum[i] = 0;
        colsum[i] = 0;
    }
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            printf("Input matrix position [%d][%d]: ", row, col);
            incheck = scanf("%d", &input);
            if(incheck != 1){
            printf("Invalid input, try again!\n");
            col--;
            //CLEARING THE INPUT BUFFER
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
            }
            in[row][col] = input;
            rowsum[row] += input;
            colsum[col] += input;
        }
    }
    for(int i = 0; i < n; i++) {
        diagsum[0] += in[i][i];
        diagsum[1] += in[i][n - 1 - i];        
    }
    for(int i = 0; i < n-1; i++){
        if(rowsum[i] != rowsum[i+1]){
            magic = 0;
            break;
        }
        if(colsum[i] != colsum[i+1]){
            magic = 0;
            break;
        }
    }
    if(rowsum[0] != colsum[0] || rowsum[0] != diagsum[0] || diagsum[0] != diagsum[1] || magic == 0){
        magic = 0;
        printf("It is not a magic matrix\n");
    }
    else{
        printf("It is a magic matrix\n");
    }
}