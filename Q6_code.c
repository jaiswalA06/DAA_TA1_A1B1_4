// Q.6: Program to find out Minimum number of platforms required for running trains

#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void *b){
    return *(int*)a-*(int*)b;
}

int minplatforms(int *arrival, int *dept, int size){
    int platforms=1, total=1,i=1,j=0;
    while(i<size && j<size){
        if(arrival[i]<=dept[j]){
            platforms++;
            i++;
        }
        else{
            platforms--;
            j++;
        }
        if(total<platforms){
            total= platforms;
        }
    }
    return total;
}

int main(){
    int size;
    printf("Enter size of both arrays: ");
    scanf("%d",&size);
    
    int *arrival=(int*)malloc(size*sizeof(int));
    int *dept=(int*)malloc(size*sizeof(int));

    printf("Enter arrival array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arrival[i]);
    }

    printf("Enter departure array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&dept[i]);
    }

    qsort(arrival, size, sizeof(int),compare);
    qsort(dept, size, sizeof(int),compare);

    int min_pf=minplatforms(arrival, dept, size);
    printf("Minimm number of platforms required: %d",min_pf);
}