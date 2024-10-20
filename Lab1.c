#include <stdio.h>
#include <stdlib.h>

int increase(int x);
int divideThree(int x);
void div2(int a);
void div25(int a);
void combine(int a);
void destoryhumanity(int a, int b, int c);
void isprime(int a);
void iscomposite(int a);

void main(){
    // int in, a = 0;
    // for(int i = 1; i < 11; i++){
    //     int out = divideThree(i);
    //     if(out == 1){
    //         printf("%d can be divided by three\n", i);
    //     }
    //     else{
    //         printf("%d cannot be divided by three\n", i);
    //     }
    // }
    // while(a < 10){
    //     a = increase(a);
    //     printf("%d\n", a);
    // }
    // div2(487758);
    // div25(10);
    // combine(482);
    destoryhumanity(3, 6, 7);
    isprime(2);
    isprime(4);
    iscomposite(4);
    iscomposite(139);
}

int divideThree(int x){
    if(x%3 == 0){
        return 1;
    }
    return 0;
}

int increase(int x){
    return ++x;
}

void div2(int a){
    a /= 2;
    if(a < 10){
        printf("Single digit number: %d\n", a);
        return;
    }
    printf("Number divided by 2: %d\n", a);
    return div2(a);
}

void div25(int a){
    if(a%5 == 0 && a%2 == 0){
        printf("%d is divisible by 2 and 5\n", a);
        return;
    }
    printf("%d is not divisible by 2 and 5\n", a);
}

void combine(int a){
    printf("Starting digits: %d\n", a);
    int tempc = a % 10;
    a /= 10;
    int tempb = a % 10;
    a /= 10;
    printf("Seperated digits: %d %d %d\n", a, tempb, tempc);
    a += tempb;
    printf("Left two digits added: %d %d\n", a, tempc);
    tempb = a%10;
    a /= 10;
    printf("Left two digits seperated: %d %d %d\n", a, tempb, tempc);
    printf("All digits added together: %d\n", a + tempb + tempc);
}

void destoryhumanity(int a, int b, int c){
    printf("Humanity is destroyed: %d\n", a*100 + b*10 + c);
}

void isprime(int a){
    int div = 0;
    for(int i = a - 1; i > 1; i--){
        if(a%i == 0){
            div = 1;
            break;
        }
    }
    if(div){
        printf("%d is not prime\n", a);
        return;
    }
    printf("%d is prime\n", a);
}

void iscomposite(int a){
    int div = 0;
    for(int i = a - 1; i > 1; i--){
        if(a%i == 0){
            div = 1;
            break;
        }
    }
    if(div){
        printf("%d is composite\n", a);
        return;
    }
    printf("%d is not composite\n", a);
}