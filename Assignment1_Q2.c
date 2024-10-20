#include <stdio.h>
#include <limits.h>

/* A retail store maintains a record of daily sales for N products. Each product has a unique
ID and the number of units sold per day is stored in an array. Write a C program that:
1. Stores the sales data in an array for N products.
2. Calculates and displays the total sales for all products combined.
3. Identifies the product ID with the maximum sales.
4. Identifies the product ID with the minimum sales.
Constraints:
• N should be between 10 and 100.
• The product IDs should start from 1 and correspond to the index of the array */

void main(){
    int n = -1, ncheck = -1, incheck = -1, in, max = INT_MIN, min = INT_MAX, count = 0, maxpos = -1, minpos = -1;
    printf("How many products would you like to take in: ");
    ncheck = scanf("%d", &n);
    if(ncheck != 1 || n < 10 || n > 100){
        printf("Invalid input!\nQuitting program.\n");
        return;
    }
    int products[n];
    for(int i = 0; i < n; i++){
        printf("Input product %d's sale count: ", i + 1);
        incheck = scanf("%d", &in);
        if(incheck != 1){
            printf("Invalid input, try again!\n");
            i--;
            //CLEARING THE INPUT BUFFER
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        products[i] = in;
        if(products[i] > max){
            max = products[i];
            maxpos = i;
        }
        if(products[i] < min){
            min = products[i];
            minpos = i;
        }
        count += products[i];
    }
    printf("Max products sold: Product %d with %d sales\nMin products sold: Product %d with %d sales\nTotal products sold: %d", maxpos + 1, max, minpos + 1, min, count);
}