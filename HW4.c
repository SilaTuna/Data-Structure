#include <stdio.h>
//MAX Heap
int size = 0;

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void maxHeapify(int array[], int size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] > array[largest])
        largest = l;
    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        maxHeapify(array, size, largest);
    }
}

void insert(int array[], int newNum) {
    if (size == 0) {
        array[0] = newNum;
        size += 1;
    } else {
        array[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--) {
            maxHeapify(array, size, i);
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[10];

    insert(array, 3);
    insert(array, 9);
    insert(array, 2);
    insert(array, 1);
    insert(array, 4);
    insert(array, 5);

    printf("Max-Heap: ");
    printArray(array, size);

    return 0;
}

//MIN Heap
void minHeapify(int array[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] < array[smallest])
        smallest = l;
    if (r < size && array[r] < array[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&array[i], &array[smallest]);
        minHeapify(array, size, smallest);
    }
}

void insertMinHeap(int array[], int newNum) {
    if (size == 0) {
        array[0] = newNum;
        size += 1;
    } else {
        array[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--) {
            minHeapify(array, size, i);
        }
    }
}
