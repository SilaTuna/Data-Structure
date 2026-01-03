#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    struct Node* temp = head;
    printf("Liste: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Basa Doner)\n");
}

void addfront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        new_node->next = *head_ref;
        temp->next = new_node;
        *head_ref = new_node;
    }
    printf(">> %d basa eklendi.\n", new_data);
}

void addlast(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head_ref;
    }
    printf(">> %d sona eklendi.\n", new_data);
}

void addmiddle(struct Node** head_ref, int index, int new_data) {
    if (index == 0 || *head_ref == NULL) {
        addfront(head_ref, new_data);
        return;
    }
    struct Node* temp = *head_ref;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
        if (temp == *head_ref) {
            printf(">> Hata: Gecersiz index!\n");
            return;
        }
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = temp->next;
    temp->next = new_node;
    printf(">> %d, %d. indexe eklendi.\n", new_data, index);
}

void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) return;
    struct Node *curr = *head_ref, *prev;
    if (curr->data == key) {
        if (curr->next == *head_ref) {
            free(curr);
            *head_ref = NULL;
        } else {
            struct Node* last = *head_ref;
            while (last->next != *head_ref) {
                last = last->next;
            }
            *head_ref = curr->next;
            last->next = *head_ref;
            free(curr);
        }
        printf(">> %d silindi.\n", key);
        return;
    }
    prev = curr;
    curr = curr->next;
    while (curr != *head_ref) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            printf(">> %d silindi.\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf(">> %d bulunamadi.\n", key);
}

int main() {
    struct Node* head = NULL;
    int secim, sayi, index;
    while (1) {
        printf("\n MENU  \n");
        printf("1. Basa Ekle\n2. Sona Ekle\n3. Araya Ekle\n4. Sil\n5. Listele\n6. Cikis\nSeciminiz: ");
        scanf("%d", &secim);
        switch (secim) {
            case 1: printf("Sayi: "); scanf("%d", &sayi); addfront(&head, sayi); break;
            case 2: printf("Sayi: "); scanf("%d", &sayi); addlast(&head, sayi); break;
            case 3: printf("Index: "); scanf("%d", &index); printf("Sayi: "); scanf("%d", &sayi); addmiddle(&head, index, sayi); break;
            case 4: printf("Silinecek: "); scanf("%d", &sayi); deleteNode(&head, sayi); break;
            case 5: printList(head); break;
            case 6: exit(0);
            default: printf("Gecersiz secim!\n");
        }
    }
    return 0;
}
