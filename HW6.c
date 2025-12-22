#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n) {
    if (n == NULL) {
        printf("Liste bos.\n");
        return;
    }
    printf("Liste: ");
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

void addfront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf(">> %d basa eklendi.\n", new_data);
}

void addlast(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; 

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        printf(">> %d sona eklendi (ilk eleman).\n", new_data);
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    printf(">> %d sona eklendi.\n", new_data);
}

void addmiddle(struct Node** head_ref, int index, int new_data) {
    if (index == 0 || *head_ref == NULL) {
        addfront(head_ref, new_data);
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    
    struct Node* temp = *head_ref;

    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf(">> Hata: Belirtilen pozisyon liste sinirlari disinda.\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    
    printf(">> %d, %d. indexe eklendi.\n", new_data, index);
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf(">> %d silindi.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf(">> %d listede bulunamadi.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf(">> %d silindi.\n", key);
}

int main() {
    struct Node* head = NULL;
    int secim, sayi, index;

    while (1) {
        printf("\n--------------------------------\n");
        printf("      MENU      \n");
        printf("--------------------------------\n");
        printf("1. Basa Ekle\n");
        printf("2. Sona Ekle\n");
        printf("3. Araya Ekle (Index ile)\n");
        printf("4. Sil (Deger ile)\n");
        printf("5. Listeyi Yazdir\n");
        printf("6. Cikis\n");
        printf("--------------------------------\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Basa eklenecek sayiyi girin: ");
                scanf("%d", &sayi);
                addfront(&head, sayi);
                break;

            case 2:
                printf("Sona eklenecek sayiyi girin: ");
                scanf("%d", &sayi);
                addlast(&head, sayi);
                break;

            case 3:
                printf("Hangi index'e eklenecek: ");
                scanf("%d", &index);
                printf("Eklenecek sayiyi girin: ");
                scanf("%d", &sayi);
                addmiddle(&head, index, sayi);
                break;

            case 4:
                printf("Silinecek sayiyi girin: ");
                scanf("%d", &sayi);
                deleteNode(&head, sayi);
                break;

            case 5:
                printList(head);
                break;

            case 6:
                printf("Programdan cikiliyor...\n");
                exit(0);
                break;

            default:
                printf(">> Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
    }

    return 0;
}
