//using Arrays

#include<stdio.h>
#include<string.h>

#define size 3

typedef struct{
    int key;
    char value[50];
}Maps;

void search(Maps map[],int k){
    int i;
    for(i =0; i<size;i++){
        if(map[i].key==k){
            printf("Value for key %d is %s",k,map[i].value);
            break;
        }
    }
    if(i==size)
        printf("Key not found!");
}

int main(){
    Maps map[size];
    int k;
    
    map[0].key=1;
    strcpy(map[0].value,"Adarsh");
    map[1].key=6;
    strcpy(map[1].value,"Divya");
    map[2].key=30;
    strcpy(map[2].value,"Vidhi");

    printf("Enter a key to search: ");
    scanf("%d",&k);
    search(map,k);

}