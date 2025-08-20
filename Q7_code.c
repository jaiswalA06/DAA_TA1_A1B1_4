//Q.7: Lemonade Change problem.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool lemonadeChange(int *bills, int size){
    int five=0,ten=0;
    for(int i=0;i<size;i++){
        if(bills[i]==5){
            five++;
        }
        else if(bills[i]==10){
            if(five>0){
                five--;ten++;
            }
            else{
                return false;
            }
        }
        else{
            if(five>0 && ten>0){
                five--;
                ten--;
            }
            else if(five>=3){
                five-=3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    int size;
    printf("Enter number of customers: ");
    scanf("%d",&size);
    int *bills=(int*)malloc(size*sizeof(int));

    printf("Enter bills array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&bills[i]);
    }

    if(lemonadeChange(bills,size)){
        printf("Change can be given to all customers!");
    }

    else{
        printf("Change cannot be given to all customers.");
    }

    return 0;
}