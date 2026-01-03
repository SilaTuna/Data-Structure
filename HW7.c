#include <stdio.h>

#define MAX 10

void diziyiYazdir(int arr[], int n) {
    printf("Dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void elemanEkle(int arr[], int *n, int kapasite, int yeniSayi, int index) {
    if (*n >= kapasite || index < 0 || index > *n) {
        return;
    }

    for (int i = *n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = yeniSayi;
    (*n)++;
}

void elemanSil(int arr[], int *n, int index) {
    if (*n <= 0 || index < 0 || index >= *n) {
        return;
    }

    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

int main() {
    int dizi[MAX] = {10, 20, 30, 40, 50};
    int mevcutBoyut = 5;

    diziyiYazdir(dizi, mevcutBoyut);

    elemanEkle(dizi, &mevcutBoyut, MAX, 99, 2);
    diziyiYazdir(dizi, mevcutBoyut);

    elemanSil(dizi, &mevcutBoyut, 4);
    diziyiYazdir(dizi, mevcutBoyut);

    return 0;
}
