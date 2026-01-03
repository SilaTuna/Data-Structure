#include <stdio.h>

#define MAX_SIZE 10

char tree[MAX_SIZE];

void set_root(char key) {
    tree[0] = key;
}

void set_left(char key, int parent_index) {
    int left_child = (parent_index * 2) + 1;
    if (tree[parent_index] == '\0') {
        printf("Hata: Ebeveyn bulunamadi!\n");
    } else if (left_child >= MAX_SIZE) {
        printf("Hata: Dizi siniri asildi!\n");
    } else {
        tree[left_child] = key;
    }
}

void set_right(char key, int parent_index) {
    int right_child = (parent_index * 2) + 2;
    if (tree[parent_index] == '\0') {
        printf("Hata: Ebeveyn bulunamadi!\n");
    } else if (right_child >= MAX_SIZE) {
        printf("Hata: Dizi siniri asildi!\n");
    } else {
        tree[right_child] = key;
    }
}

void print_tree() {
    printf("\nAgac Dizisi: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i] == '\0')
            printf("- ");
        else
            printf("%c ", tree[i]);
    }
    printf("\n");
}

int main() {
    for(int i = 0; i < MAX_SIZE; i++) tree[i] = '\0';

    set_root('A');
    set_left('B', 0);
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 1);
    set_right('F', 2);

    print_tree();

    return 0;
}
