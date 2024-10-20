#include <stdio.h>
#include <limits.h>

void main(){   
    // int arr[10];
    // for(int i = 0; i < 10; i++){
    //     printf("Enter value %d for the array: ", i+1);
    //     scanf("%d", &arr[i]);
    // }
    // for(int i = 0; i < sizeof(arr)/4; i++){
    //     printf("%d\n", arr[i]);
    // }
    // int a[] = {3, 7, 9, 11, 21};
    // int max = INT_MIN, min = INT_MAX;
    // for(int i = 0; i < sizeof(a)/4; i++){
    //     if(max < a[i]){
    //         max = a[i];
    //     }
    //     if(min > a[i]){
    //         min = a[i];
    //     }
    // }
    // printf("Minimum value in array: %d\nMaximum value in array: %d\n", min, max);
    int a[] = {0, 1, 3, 1, 3, 1, 0};
    int val = -1, count = -1, hcount = -1, final = -1, size = sizeof(a)/4;
    int used[size];
    for(int i = 0; i < size; i++){
        val = a[i];
        for(int c = 0; c < i; c++){
            if(used[c] == val){
                continue;
            }
        }
        used[i] = val;
        count = 0;
        for(int j = 0; j < size; j++){
            if(val == a[j]){
                count += 1;
                if(count > hcount){
                    hcount = count;
                    final = val;
                }
            }
        }
    }
    printf("Highest occuring value: %d with %d occurances\n", final, hcount);
    
    for(int i = 0; i < size; i++){
        count = 0;
        for(int j = 0; j < size; j++){
            if(a[i] == a[j]){
                count++;
            }
        }
        if(count > size/2){
            printf("Highest occuring value: %d with %d occurances\n", a[i], count);
            break;
        }
    }
}