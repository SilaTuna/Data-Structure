#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* create_linkedlist(int data) {
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void write_linkedlist(node* n) {
    node* temp = n;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n----\n");
}

void add_node_head_of_linkedlist(node** linkedlist, int data) {
    node* new_node = create_linkedlist(data);
    new_node->next = *linkedlist;
    *linkedlist = new_node;
}

void add_node_end_of_linkedlist(node** linkedlist, int data) {
    if (*linkedlist == NULL) {
        *linkedlist = create_linkedlist(data);
        return;
    }
    node* temp = *linkedlist;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = create_linkedlist(data);
}

void add_node_after_value(node* linkedlist, int after_data, int new_data) {
    node* temp = linkedlist;
    while (temp != NULL && temp->data != after_data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found. Cannot insert.\n", after_data);
        return;
    }
    node* new_node = create_linkedlist(new_data);
    new_node->next = temp->next;
    temp->next = new_node;
}


void delete_node_from_linkedlist(node** linkedlist, int data) {
    if (*linkedlist == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    node* temp = *linkedlist;
    node* prev = NULL;

    // Begining
    if (temp != NULL && temp->data == data) {
        *linkedlist = temp->next;
        free(temp);
        return;
    }

    // Inside
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Not found
    if (temp == NULL) {
        printf("Data %d not found.\n", data);
        return;
    }


    prev->next = temp->next;
    free(temp);
}

int main() {
    node* root = create_linkedlist(3);
    add_node_head_of_linkedlist(&root, 4);
    add_node_head_of_linkedlist(&root, 5);
    add_node_head_of_linkedlist(&root, 1);
    add_node_end_of_linkedlist(&root, 6);

    printf("Initial linked list:\n");
    write_linkedlist(root);

	// Begining
    add_node_head_of_linkedlist(&root, 9);
    // End
    add_node_end_of_linkedlist(&root, 7);
    // Inside
    add_node_after_value(root, 4, 99);

    printf("After insertions:\n");
    write_linkedlist(root);

    
    delete_node_from_linkedlist(&root, 1);
    delete_node_from_linkedlist(&root, 99);
    delete_node_from_linkedlist(&root, 7);

    printf("After deletions:\n");
    write_linkedlist(root);

    return 0;
}

