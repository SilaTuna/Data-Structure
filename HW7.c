#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        perror("Bellek ayirma hatasi");
        exit(EXIT_FAILURE);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void searchRecursive(Node* head, int aranan) {
    if (head == NULL) {
        printf("Sonuc: %d listede yok.\n", aranan);
        return;
    }

    if (head->data == aranan) {
        printf("Sonuc: %d bulundu! ", aranan, (void*)head);
        return;
    }

    searchRecursive(head->next, aranan);
}

int main() {
    Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);

    printf("Liste: 10 -> 20 -> 30 -> 40\n\n");

    searchRecursive(head, 30);
    searchRecursive(head, 99);
    
    printf("\n");

    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
