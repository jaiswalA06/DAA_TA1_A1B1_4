//Using hash map

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct MapEntry {
    int key;                    // key is now integer
    char value[50];             // value is now string
    struct MapEntry* next;
};

// Hash function for integer keys
int hash(int key) {
    return key % TABLE_SIZE;    // simple modulus hash
}

// Insert key-value pair
void insert(struct MapEntry* table[], int key, char* value) {
    int idx = hash(key);
    struct MapEntry* newNode = (struct MapEntry*)malloc(sizeof(struct MapEntry));
    newNode->key = key;
    strcpy(newNode->value, value);   // copy string into value
    newNode->next = table[idx];
    table[idx] = newNode;
}

// Search by key
char* search(struct MapEntry* table[], int key) {
    int idx = hash(key);
    struct MapEntry* node = table[idx];
    while (node) {
        if (node->key == key)
            return node->value;      // return string value
        node = node->next;
    }
    return NULL; // Not found
}

int main() {
    struct MapEntry* map[TABLE_SIZE] = { NULL };

    insert(map, 101, "apple");
    insert(map, 202, "banana");
    insert(map, 303, "grape");

    char* result = search(map, 202);
    if (result != NULL)
        printf("Value for key 202: %s\n", result);
    else
        printf("Key not found!\n");

    return 0;
}
