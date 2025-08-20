// Q.5: Program to Flattening the linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* down;
} node;

node* newNode(int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    temp->down = NULL;
    return temp;
}

// merges two lists (like merge sort)
node* merge(node* a, node* b) {
    if(a==NULL) 
        return b;
    if(b==NULL) 
        return a;

    node* result;
    if(a->data < b->data){
        result = a;
        result->down = merge(a->down, b);
    }
    else{
        result = b;
        result->down = merge(a, b->down);
    }
    result->next = NULL;  
    return result;
}

// flatten the list
node* flatten(node* root) {
    if(root==NULL || root->next==NULL) return root;

    root->next = flatten(root->next);

    root = merge(root, root->next);
    return root;
}

void printList(node* root){
    while(root!=NULL){
        printf("%d ", root->data);
        root = root->down;
    }
    printf("\n");
}

int main() {
    // sample input structure
    node* head = newNode(4);
    head->next = newNode(12);
    head->next->next = newNode(17);
    head->next->next->next = newNode(28);

    head->down = newNode(7);
    head->down->down = newNode(14);
    head->down->down->down = newNode(29);

    head->next->down = newNode(22);

    head->next->next->down = newNode(25);
    head->next->next->down->down = newNode(50);

    head->next->next->next->down = newNode(31);
    head->next->next->next->down->down = newNode(39);
    head->next->next->next->down->down->down = newNode(45);

    head = flatten(head);

    printf("Flattened linked list is:\n");
    printList(head);

    return 0;
}
