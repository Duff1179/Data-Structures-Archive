#include <stdio.h>

void main(){
    int n = -1, ncheck = -1, m = -1, mcheck = -1, input = -1, incheck = -1;
    printf("How many rows should your matrix have: ");
    ncheck = scanf("%d", &n);
    printf("How many columns should your matrix have: ");
    mcheck = scanf("%d", &m);
    if(ncheck != 1 || mcheck != 1 || n < 3 || n > 10 || m < 3 || m > 10){
        printf("Invalid input!\nQuitting program.\n");
        return;
    }
    int in[m][n];
    int rowsum[m];
    int colsum[n];
    for(int i = 0; i < m; i++){
        rowsum[i] = 0;
    }
    for(int i = 0; i < n; i++){
        colsum[i] = 0;
    }
    for(int row = 0; row < m; row++){
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
            rowsum[row] += input;
            colsum[col] += input;
            in[row][col] = input;
        }
    }
    printf("Matrix:\n");
    for(int row = 0; row < m; row++){
        for(int col = 0; col < n; col++){
            printf("%d ", in[row][col]);
        }
        printf("\n");
    }
    printf("Row Sums: ");
    for(int i = 0; i < 3; i++){
        printf("%d ", rowsum[i]);
    }
    printf("\nCol Sums: ");
    for(int i = 0; i < 3; i++){
        printf("%d ", colsum[i]);
    }
}