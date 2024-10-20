#include <stdio.h>

void main(){
    int a[] = {0, 1, 0, 2, 2, 1, 1};
    int zero = 0, one = 0, two = 0;
    for(int i = 0; i < sizeof(a)/4; i++){
        if(a[i] == 0){
            zero++;
        }
        if(a[i] == 1){
            one++;
        }
        if(a[i] == 2){
            two++;
        }
    }
    int b[7];
    for(int i = 0; i < sizeof(a)/4; i++){
        if(zero > 0){
            b[i] = 0;
            zero--;
        }
        else if(one > 0){
            b[i] = 1;
            one--;
        }
        else if(two > 0){
            b[i] = 2;
            two--;
        }
        printf("%d\n", b[i]);
    }
}