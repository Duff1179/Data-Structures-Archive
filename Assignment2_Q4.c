#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef union{
    char title[50];
    char author[50];
    int pCount;
    float price;
}book;

void addBook(book books[], book authors[], book prices[], book pCounts[], int index);
void printBook(book books[], book authors[], book prices[], book pCounts[], int index);
void printBAT(book books[], book authors[], book prices[], book pCounts[], int size, float threshold);

void main(){
    int count, ccheck, tcheck;
    float threshold;
    printf("How many books would you like to import: ");
    ccheck = scanf("%d", &count);
    if(!ccheck || count < 0 || count > 30){
        printf("Invalid Input!\nQuitting Program!");
        return;
    }
    printf("Input your price printing threshold: ");
    tcheck = scanf("%f", &threshold);
    if(!tcheck || threshold < 0){
        printf("Invalid Input!\nQuitting Program!");
        return;
    }
    book books[count];
    book authors[count];
    book prices[count];
    book pCounts[count];
    for(int i = 0; i < count; i++){
        addBook(books, authors, prices, pCounts, i);
    }
    // for(int i = 0; i < count; i++){
    //     printBook(books, authors, prices, pCounts, i);
    // }
    printBAT(books, authors, prices, pCounts, count, threshold);
}

void addBook(book books[], book authors[], book prices[], book pCounts[], int index){
    int pCount, check;
    char title[50], author[50];
    float price;
    printf("Enter the page count and price of the book (290 29.99): ");
    check = scanf("%d %f", &pCount, &price);
    int ch; //clear input for fgets (and if you put in the wrong input)
    while ((ch = getchar()) != '\n' && ch != EOF);
    if(!check || pCount < 0 || price < 0){
        printf("Invalid Input!\nPlease Try Again!\n");
        addBook(books, authors, prices, pCounts, index);
    }
    printf("Enter the name of the book: ");
    fgets(title, sizeof(title), stdin);
    int loc = strcspn(title, "\n"); //removing the new line char for the title
    title[loc] = '\0';
    printf("Enter the author of the book: ");
    fgets(author, sizeof(author), stdin);
    loc = strcspn(author, "\n");
    author[loc] = '\0';
    pCounts[index].pCount = pCount;
    prices[index].price = price;
    strcpy(authors[index].author, author);
    strcpy(books[index].title, title);
}

void printBook(book books[], book authors[], book prices[], book pCounts[], int index){
    printf("Book %d, title: %s, author: %s, price: %.2f, page count: %d\n", index, books[index].title, authors[index].author, prices[index].price, pCounts[index].pCount);
}

void printBAT(book books[], book authors[], book prices[], book pCounts[], int size, float threshold){
    for(int i = 0; i < size; i++){
        if(prices[i].price > threshold){
            printBook(books, authors, prices, pCounts, i);
        }
    }
}
