#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct{
    char model[50];
    int year;
    float price;
}car;

void addCar(car cars[], int index);
void printCar(car cars[], int index);
void cheapest(car cars[], int size);
void avgPrice(car cars[], int size);


void main(){
    int count, ccheck;
    printf("How many cars would you like to import: ");
    ccheck = scanf("%d", &count);
    if(!ccheck || count < 5 || count > 20){
        printf("Invalid Input!\nQuitting Program!");
        return;
    }
    car cars[count];
    for(int i = 0; i < count; i++){
        addCar(cars, i);
    }
    for(int i = 0; i < count; i++){
        printCar(cars, i);
    }
    cheapest(cars, count);
    avgPrice(cars, count);
}

void addCar(car cars[], int index){
    int year, ycheck, ncheck;
    float price;
    char model[50];
    printf("Input year and price of the car (1997 35000.00): ");
    ycheck = scanf("%d %f", &year, &price);
    if(!ycheck){//checking for proper input
        printf("Invalid input!\nPlease try again!\n");
        int ch; //ensuring the input buffer is clear as we got the wrong input
        while ((ch = getchar()) != '\n' && ch != EOF);
        addCar(cars, index);
    }
    printf("Input the model of your car: ");
    ncheck = scanf("%49s", model);
    if(!ncheck){//checking for proper input
        printf("Invalid input!\nPlease try again!\n");
        int ch; //ensuring the input buffer is clear as we got the wrong input
        while ((ch = getchar()) != '\n' && ch != EOF);
        addCar(cars, index);
    }
    cars[index].year = year;
    cars[index].price = price;
    strcpy(cars[index].model, model);
}

void printCar(car cars[], int index){
    printf("Car %d, Model: %s, Year: %d, Price: %.2f\n", index, cars[index].model, cars[index].year, cars[index].price);
}

void cheapest(car cars[], int size){
    float min = INT_MAX;
    int pos = -1;
    for(int i = 0; i < size; i++){
        if(min > cars[i].price){
            min = cars[i].price;
            pos = i;
        }
    }
    printf("Minimum price of $%.2f on car %d (model %s, year %d)\n", min, pos, cars[pos].model, cars[pos].year);
}

void avgPrice(car cars[], int size){
    float avg = 0;
    for(int i = 0; i < size; i++){
        avg += cars[i].price;
    }
    avg /= size;
    printf("Average price of all cars: $%.2f", avg);
}