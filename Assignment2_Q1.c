#include <stdio.h>
#include <string.h>
#include <limits.h>

struct emp{
    char name[50];
    int age;
    float salary;
};

void addEmployee(struct emp emps[], int index);
void printEmployee(struct emp emps[], int index);
void highestSalary(struct emp emps[], int size);
void avgAge(struct emp emps[], int size);

void main(){
    int count, ccheck;
    printf("How many employees would you like to import: ");
    ccheck = scanf("%d", &count);
    if(ccheck != 1 || count < 5 || count > 50){
        printf("Invalid Input\nQuitting Program");
        return;
    }
    struct emp emps[count];
    for(int i = 0; i < count; i++){
        addEmployee(emps, i);
    }
    // for(int i = 0; i < count; i++){
    //     printEmployee(emps, i);
    // }
    highestSalary(emps, count);
    avgAge(emps, count);
}

void addEmployee(struct emp emps[], int index){
    int age, acheck, ncheck;
    float salary;
    char name[50];
    printf("Import the age and the salary (ex. 49 4900.3): ");
    acheck = scanf("%d %f", &age, &salary);
    if(!acheck){//checking for proper input
        printf("Invalid input!\nPlease try again!\n");
        int ch; //ensuring the input buffer is clear as we got the wrong input
        while ((ch = getchar()) != '\n' && ch != EOF);
        addEmployee(emps, index);
    }
    int ch; //ensuring the input buffer is clear for the string input
    while ((ch = getchar()) != '\n' && ch != EOF);
    printf("Import your employee's name: ");
    ncheck = scanf("%49s", name);
    if(!ncheck){//checking for proper input
        printf("Invalid input!\nPlease try again!\n");
        int ch; //ensuring the input buffer is clear as we got the wrong input
        while ((ch = getchar()) != '\n' && ch != EOF);
        addEmployee(emps, index);
    }
    emps[index].age = age;
    emps[index].salary = salary;
    strcpy(emps[index].name, name);
}

void printEmployee(struct emp emps[], int index){
    printf("Employee %d, Name: %s, Age: %d, Salary %.2f\n", index, emps[index].name, emps[index].age, emps[index].salary);
}

void highestSalary(struct emp emps[], int size){
    float max = INT_MIN;
    int pos = -1;
    for(int i = 0; i < size; i++){
        if(max < emps[i].salary){
            max = emps[i].salary;
            pos = i;
        }
    }
    printf("Maximum salary: %.2f from employee %d (Name: %s, Age %d)\n", max, pos, emps[pos].name, emps[pos].age);
}

void avgAge(struct emp emps[], int size){
    float avg = 0;
    for(int i = 0; i < size; i++){
        avg += emps[i].age;
    }
    avg /= size;
    printf("Average age of employees: %.2f\n", avg);
}