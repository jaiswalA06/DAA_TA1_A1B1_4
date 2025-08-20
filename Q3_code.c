#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int floydsLoopDetection(node* first){
    node *ptr1=first, *ptr2=first;

    while(ptr1!=NULL && ptr2!=NULL && ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;

        if(ptr1==ptr2){
            return 1;
        }
    }
    return 0;
}

int main(){
    node* first = createNode(1);
    first->next = createNode(4);
    first->next->next = createNode(23);
    first->next->next->next = createNode(11);
    first->next->next->next->next = createNode(8);
    first->next->next->next->next->next = first->next; 

    if (floydsLoopDetection(first))
        printf("Loop detected in linked list!\n");
    else
        printf("No loop detected in linked list\n");

    return 0;
}

