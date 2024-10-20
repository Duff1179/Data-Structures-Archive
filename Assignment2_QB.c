#include <stdio.h>
#include <string.h>

typedef struct{
    int a;
    float b;
    double c;
}str;

typedef union{
    int a;
    float b;
    double c;
}uni;


void main(){
    str a = {200, 2.01, 2.000001};
    uni b = {200 };
    printf("Memory of the structure: %d\nMemory of the union: %d\n", sizeof(a), sizeof(b));
    printf("Data for the structure\n[%d, %.2f, %.6lf]\nData for the union\n[%d, %.2f, %.6lf]", a.a, a.b, a.c, b.a, b.b, b.c);
    /*
    Unions can only hold 1 element at a time, so its memory usage is the size of the highest data (in this case 8)
    Structures can hold all of its elements at a time, so its memory usage is the sum of all the data types (in this case 16)
    */
}