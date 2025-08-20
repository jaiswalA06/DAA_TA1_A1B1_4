//Program to detect the longet conscutive sequence in an array

#include<stdio.h>
#include<stdlib.h>

int compare(const void *a,const void *b){
    int x=*(int*)a;
    int y=*(int*)b;
    return x-y;
}

int longestConsecutiveSequence(int *arr,int size){
    int count=1,longest=1;
    for(int i=0;i<size-1;i++){
        if(arr[i]==arr[i+1]){
            continue;
        }
        else if(arr[i+1]-arr[i]==1){
            count++;
            if(count>longest){
                longest=count;
            }
        }
        else{
            count=1;
        }
    }
    return longest;
}

int main(){
    int size;
    printf("Enter size of arr: ");
    scanf("%d",&size);
    int *arr=(int*)malloc(size*sizeof(int));
    printf("enter elements of array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr,size,sizeof(int),compare);

    int longest=longestConsecutiveSequence(arr,size);
    printf("The longest consecutive sequence: %d",longest);

    return 0;
}
