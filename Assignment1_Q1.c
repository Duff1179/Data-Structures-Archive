#include <stdio.h>
#include <limits.h>

/* A weather station records the daily temperatures for N days. You are required to write a C program that performs the following tasks:
1. Store the temperatures of the N days in an array.
2. Find the maximum temperature and the minimum temperature recorded
over these days using a loop.
3. Calculate the number of days where the temperature was above a user-defined
threshold T.
4. Display the total number of days above the threshold, and the maximum and minimum temperatures.
Constraints:
• N should be between 10 and 1000.*/

void main(){
    int n = -1, t = -1, tcheck = -1, ncheck = -1, incheck = -1, in, max = INT_MIN, min = INT_MAX, count = 0;
    printf("How many temperatures would you like to take in: ");
    ncheck = scanf("%d", &n);
    printf("What is your threshold: ");
    tcheck = scanf("%d", &t);
    if(tcheck != 1 || ncheck != 1 || n < 10 || n > 1000){
        printf("Invalid input!\nQuitting program.\n");
        return;
    }
    int temps[n];
    for(int i = 0; i < n; i++){
        printf("Input day %d's temperature: ", i + 1);
        incheck = scanf("%d", &in);
        if(incheck != 1){
            printf("Invalid input, try again!\n");
            i--;
            //CLEARING THE INPUT BUFFER
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        temps[i] = in;
        if(temps[i] > max){
            max = temps[i];
        }
        if(temps[i] < min){
            min = temps[i];
        }
        if(temps[i] > t){
            count++;
        }

    }
    printf("Max temp: %d\nMin temp: %d\nDays above threshold (%d): %d", max, min, t, count);
}