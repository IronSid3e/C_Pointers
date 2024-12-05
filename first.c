#include <stdio.h>

int main(){

    int Arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    int *ptr = Arr;

    printf("Dizinin elemanlari : \n");
    for (int i = 0; i < size; i++) {
        printf("%d  ", *(ptr + i));
    }
    
    return 0;
}