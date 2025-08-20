#include <stdio.h>
#include<stdlib.h>

int mooreAlgo(int* arr, int size) {
    int candidate = 0, count = 0;

    for (int i = 0; i < size; i++) {
        if (count == 0)
            candidate = arr[i];
        
        if (arr[i] == candidate)
            count++;
        else
            count--;
    }

    count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] == candidate)
            count++;

    if(count>size/2)
        return candidate;
    
    else
        return -1;
}

int main() {
    int size;
    printf("Enter size: ");
    scanf("%d",&size);
    int *arr=(int*)malloc(sizeof(int)*size);
    printf("Enter elements of array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int majority = mooreAlgo(arr, size);
    
    if (majority != -1)
        printf("Majority Element: %d\n", majority);
    else
        printf("No Majority Element\n");
    
    return 0;
}
