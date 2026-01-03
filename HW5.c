#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} node;

node* create_node(int data) {
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void write_linkedlist(node* n) {
    node* temp = n;
    node* last = NULL;

    printf("Ileri: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        last = temp;
        temp = temp->next;
    }
    
    printf("\nGeri:  ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n----\n");
}

void add_node_
