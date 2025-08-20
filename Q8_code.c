// Q.8: Program to remove the nth back node from Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;


node* insert(node* head,int val){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        node *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return head;
}

node* delete(node* head, int n,int size){
    int num=size-n;
    int i=1;
    node* ptr= head; node* nextnode;
    if(n>size){
        printf("Cannot delete. Invalid request!");
        return head;
    }
    else{
        while(i<num){
            ptr=ptr->next;
            i++;
        }
        nextnode=ptr->next;
        ptr->next=nextnode->next;
        free(nextnode);
        return head;
    }    
}

int main(){
    node* head=NULL;
    int size,val,n;
    printf("Enter size of linked list: ");
    scanf("%d",&size);

    printf("Enter elements for linked list: ");
    for(int i=0;i<size;i++){
        scanf("%d",&val);
        head=insert(head,val);
    }
    node* ptr=head;
    printf("Original linked list: ");
    while(ptr->next!=NULL){
            printf("%d->",ptr->data);
            ptr=ptr->next;
    }
    printf("%d",ptr->data);

    printf("\nEnter nth node from back to be deleted: ");
    scanf("%d",&n);

    head=delete(head,n,size);
    ptr=head;
    if(ptr==NULL){
        printf("\nEmpty linked list!");
    }
    else{
        while(ptr->next!=NULL){
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
    return 0;
}