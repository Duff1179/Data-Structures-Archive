#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef union{
    char name[50];
    int id;
    int grade[3];
}student;

void addStudent(student name[], student id[], student grades[], int index);
void printStudent(student name[], student id[], student grades[], int index);
void avgGrade(student name[], student id[], student grades[], int size);
void maxGrade(student name[], student id[], student grades[], int size);

void main(){
    int count, ccheck;
    printf("How many students would you like to import: ");
    ccheck = scanf("%d", &count);
    if(ccheck != 1 || count < 3 || count > 30){//making sure input is proper and in the appropirate constraints
        printf("Invalid Input!\nQuitting Program!");
        return;
    }
    student names[count];
    student ids[count];
    student grades[count];
    for(int i = 0; i < count; i++){
        addStudent(names, ids, grades, i);
    }
    // for(int i = 0; i < count; i++){
    //     printStudent(names, ids, grades, i);
    // }
    avgGrade(names, ids, grades, count);
    maxGrade(names, ids, grades, count);
}

void addStudent(student names[], student ids[], student grades[], int index){
    int idin, grade1, grade2, grade3, idcheck, ncheck;
    char namein[50];
    printf("Input the student's id and 3 grades (id grade1 grade2 grade3): ");
    idcheck = scanf("%d %d %d %d", &idin, &grade1, &grade2, &grade3);
    if(!idcheck){//checking for proper input
        printf("Invalid input!\nPlease try again!\n");
        int ch; //ensuring the input buffer is clear as we got the wrong input
        while ((ch = getchar()) != '\n' && ch != EOF);
        addStudent(names, ids, grades, index);
    }
    int ch; //ensuring the input buffer is clear for the string input
    while ((ch = getchar()) != '\n' && ch != EOF);
    printf("Input the student's name: ");
    scanf("%49s", namein);
    if(!ncheck){//checking for proper input
        printf("Invalid input!\nPlease try again!\n");
        int ch; //ensuring the input buffer is clear as we got the wrong input
        while ((ch = getchar()) != '\n' && ch != EOF);
        addStudent(names, ids, grades, index);
    }
    strcpy(names[index].name, namein);
    ids[index].id = idin;
    grades[index].grade[0] = grade1;
    grades[index].grade[1] = grade2;
    grades[index].grade[2] = grade3;
}

void printStudent(student names[], student ids[], student grades[], int index){
    printf("Student %d, Name: %s, ID: %d, Grades: [%d, %d, %d]\n", index, names[index].name, ids[index].id, grades[index].grade[0], grades[index].grade[1], grades[index].grade[2]);
}

void avgGrade(student names[], student ids[], student grades[], int size){
    float avg = 0;
    for(int i = 0; i < size; i++){
        avg = (grades[i].grade[0] + grades[i].grade[1] + grades[i].grade[2])/3;
        printf("Student %s (ID: %d) has a grade average of: %.2f\n", names[i].name, ids[i].id, avg);
    }
}

void maxGrade(student names[], student ids[], student grades[], int size){
    int sum = 0;
    int max = INT_MIN;
    int pos = -1;
    for(int i = 0; i < size; i++){
        sum = grades[i].grade[0] + grades[i].grade[1] + grades[i].grade[2];
        if(max < sum){
            max = sum;
            pos = i;
        }
    }
    printf("Student %d (Name: %s, ID: %d), has the maximum total grade of the class (%d)\n", pos, names[pos].name, ids[pos].id, max);
}