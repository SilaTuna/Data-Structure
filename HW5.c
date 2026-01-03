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

void add_node_head(node** linkedlist, int data) {
    node* new_node = create_node(data);
    if (*linkedlist != NULL) {
        new_node->next = *linkedlist;
        (*linkedlist)->prev = new_node;
    }
    *linkedlist = new_node;
}

void add_node_end(node** linkedlist, int data) {
    node* new_node = create_node(data);
    if (*linkedlist == NULL) {
        *linkedlist = new_node;
        return;
    }
    node* temp = *linkedlist;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void add_node_after_value(node* linkedlist, int after_data, int new_data) {
    node* temp = linkedlist;
    while (temp != NULL && temp->data != after_data) {
        temp = temp->next;
    }
    
    if (temp == NULL) return;

    node* new_node = create_node(new_data);
    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

void delete_node(node** linkedlist, int data) {
    if (*linkedlist == NULL) return;

    node* temp = *linkedlist;

    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (*linkedlist == temp) {
        *linkedlist = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

int main() {
    node* root = NULL;

    add_node_end(&root, 10);
    add_node_end(&root, 20);
    add_node_head(&root, 5);
    add_node_after_value(root, 10, 15);

    write_linkedlist(root);

    delete_node(&root, 5);
    delete_node(&root, 15);
    delete_node(&root, 20);

    write_linkedlist(root);

    return 0;
}
