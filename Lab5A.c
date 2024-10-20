#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int age;
    char name[10];
}person;

struct karr{
    int a[6];
    int key;
};

struct arr{
    int a[6];
};

struct info{
    int age;
    int height;
    char name[50];
    int id;
};

typedef struct{
    struct info I; //person who's taking the course
    int cGPA; //course gpa requirment
    int cID; //course ID
}courseDetail;

typedef struct{
    int age;
    double weight;
    double height;
    char name[50];
}BMI;

void setupCourse(courseDetail *cD, char *n, int id, int h, int a, int cGPA, int cID);
void printCourse(courseDetail *cD);
void setBMI(BMI *a, int age, double w, double h, char *n);
void printBMI(BMI *a);

void main(){
    char namein[10] = "Dylan";
    int agein = 19;
    person one;
    one.age = agein;
    strcpy(one.name, namein);
    printf("New \"person\" structure created:\nName: %s\nAge: %d\n\n", one.name, one.age);

    struct karr two = {{1, 3, 5, 9, 10, 11}, 9};
    printf("New \"karr\" structure created: ");
    for(int i = 0; i < sizeof(two.a)/4; i++){
        printf("%d ", two.a[i]);
    }
    printf("\nKey value: %d\n", two.key);
    for(int i = 0; i < sizeof(two.a)/4; i++){
        if(two.a[i] == two.key){
            printf("Key value found at position: %d\n", i);
        }
    }

    struct arr three = {1, 2, 3, 4, 5, 6};
    struct arr four = {2, 4, 7, 9, 10, 11};
    printf("Two new \"arr\" structures created: ");
    for(int i = 0; i < sizeof(three.a)/4; i++){
        printf("%d ", three.a[i]);
    }
    printf("\n");
    for(int i = 0; i < sizeof(four.a)/4; i++){
        printf("%d ", four.a[i]);
    }
    printf("\n");
    for(int i = 0; i < sizeof(three.a)/4; i++){
        for(int j = 0; j < sizeof(four.a)/4; j++){
            if(three.a[i] == four.a[j]){
                printf("Match found: %d, at position (A, B): %d, %d\n", three.a[i], i, j);
            }
        }
    }
    printf("Two new \"Course Detail\" structures created: ");
    courseDetail *cD1 = malloc(sizeof(courseDetail)); 
    courseDetail *cD2 = malloc(sizeof(courseDetail));
    char name[] = "Walker Moody";
    setupCourse(cD1, name, 63920324, 2, 99, 3, 2414);
    char name2[] = "Dylan Duffey";
    setupCourse(cD2, name2, 23456532, 6, 19, 3, 2413);
    printCourse(cD1);
    printCourse(cD2);

    BMI *five = malloc(sizeof(BMI));
    char name3[] = "Dylan Duffey";
    strcpy(five->name, name3);
    five->age = 19;
    five->height = 6.1;
    five->weight = 153.8;
    printf("New \"BMI\" structure created:\nName: %s\nAge: %d\nHeight: %.2f\nWeight: %.2f\n\n", five->name, five->age, five->height, five->weight);
    printf("New array of \"BMI\" structures created:\n");
    BMI *arr[3] = {malloc(sizeof(BMI)), malloc(sizeof(BMI)), malloc(sizeof(BMI))};
    setBMI(arr[0], 19, 150.3, 6.1, "Dylan");
    setBMI(arr[1], 22, 250.53, 7.2, "Tall Man");
    setBMI(arr[2], 99, 140.5, 5.6, "Old Man");
    printBMI(arr[0]);
    printBMI(arr[1]);
    printBMI(arr[2]);
    printf("\n");    
}

void setupCourse(courseDetail *cD, char *n, int id, int h, int a, int cGPA, int cID){
    strcpy(cD->I.name, n);
    cD->I.age = a;
    cD->I.height = h;
    cD->I.id = id;
    cD->cGPA = cGPA;
    cD->cID = cID;
}
void printCourse(courseDetail *cD){
    printf("Course details:\nCourse id: %d\nGPA requirement: %d\nPerson information:\nName: %s\nID: %d\nHeight: %d\nAge: %d\n\n", cD->cID, cD->cGPA, cD->I.name, cD->I.id, cD->I.height, cD->I.age);
}
void setBMI(BMI *a, int age, double w, double h, char *n){
    a->age = age;
    a->height = h;
    a->weight = w;
    strcpy(a->name, n);
}
void printBMI(BMI *a){
    printf("Name: %s\nHeight: %.2f\nWeight: %.2f\nAge: %d\n\n", a->name, a->height, a->weight, a->age);
}