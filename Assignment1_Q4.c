#include <stdio.h>
#include <limits.h>

void main(){
    int n = -1, ncheck = -1, m = -1, mcheck = -1, input = -1, incheck = -1, maxpos = -1, minpos = -1;
    printf("How many students do you have: ");
    ncheck = scanf("%d", &n);
    printf("How many grades will each student have: ");
    mcheck = scanf("%d", &m);
    if(ncheck != 1 || mcheck != 1 || n < 3 || n > 50 || m < 3 || m > 10){
        printf("Invalid input!\nQuitting program.\n");
        return;
    }
    int in[m][n];
    float avg[m];
    for(int i = 0; i < m; i++){
        avg[i] = 0;
    }
    for(int row = 0; row < m; row++){
        for(int col = 0; col < n; col++){
            printf("Input grade %d for student %d: ", row + 1, col + 1);
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
            avg[row] += input;
        }
        avg[row] /= n;
        if(avg[row] > avg[maxpos]){
            maxpos = row;
        }
        if(avg[row] < avg[minpos]){
            minpos = row;
        }
    }
    printf("Grades Matrix:");
    for(int row = 0; row < m; row++){
        printf("\nStudent %d: ", row + 1);
        for(int col = 0; col < n; col++){
            printf("%d ", in[row][col]);
        }
    }
    printf("\nAverage Grades:");
    for(int row = 0; row < m; row++){
        printf("\nStudent %d: %.2f ", row + 1, avg[row]);
    }
    printf("\nStudents with an average greater than 75: ");
    for(int row = 0; row < m; row++){
        if(avg[row] >= 75){
            printf("\nStudent %d ", row + 1);
        }
    }
    
}