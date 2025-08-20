//Q.9: Program to Merge two sorted array without extra space

#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mergeArrays(int arr1[], int n, int arr2[], int m) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] > arr2[0]) {
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;

            int key = arr2[0];
            int j;
            for (j = 1; j < m && arr2[j] < key; j++) {
                arr2[j-1] = arr2[j];
            }
            arr2[j-1] = key;
        }
    }
}

int main() {
    int size1,size2;
    printf("Enter size of first array");
    scanf("%d",&size1);
    printf("Enter size of second array");
    scanf("%d",&size2);
    int *arr1=(int*)malloc(sizeof(int)*size1);
    int *arr2=(int*)malloc(sizeof(int)*size2);
    
    printf("Enter elements of arr1: ");
    for(int i=0;i<size1;i++){
        scanf("%d",&arr1[i]);
    }

    printf("Enter elements of arr2: ");
    for(int i=0;i<size2;i++){
        scanf("%d",&arr2[i]);
    }

    printf("Before merging:\n");
    printArray(arr1, size1);
    printArray(arr2, size2);

    mergeArrays(arr1, size1, arr2, size2);

    printf("\nAfter merging:\n");
    printArray(arr1, size1);
    printArray(arr2, size2);

    return 0;
}