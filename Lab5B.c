#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union data{
    int i;
    int j;
};

void main(){
    union data one;
    one.i = 20;
    printf("%d\n", one.i);
    one.j = 10;
    printf("%d\n", one.j);
    one.i = 25;
    one.j = 15;
    printf("%d\n", one.i);
    printf("%d\n", one.j);
    printf("%d\n", one); //or just use one because it's a stupid union
}