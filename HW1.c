#include <stdio.h>
#define MAX 100

int arr[MAX];
int size = 0;

//Ekleme(Insert)
void insert(int value){
	if(size == MAX) {
		printf("Diziye ekleme yapilamadi. Dizi dolu!\n");
		return;
	}
	arr[size] = value;
	size++;
}

//Silme(Delete)
void delete(int value){
	int i, j;
	for (i=0; i< size; i++){
		if(arr[i] == value){
			for(j = i; j < size -1; j++){
				arr[j] = arr[j +1];
			}
			size--;
		printf("%d Silindi.\n", value);
		return;
		}
	}
	printf("%d Girilen veri bulunamadi, silinemedi.\n", value);
}

//Arama(search)
int search(int value){
	for(int i = 0; i < size; i++){
		if(arr[i] == value){
			return i;
		}
	}
	return -1;
}

void printArray(){
	printf("Dizi: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
	
	int n, value;
	
	printf("Dizinin eleman sayisini giriniz: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("arr[%d] =", i);
		scanf("%d",&value);
		insert(value);
	}
	
	int choice;
	
	do {
		printf("\n MENU \n");
		printf("1. Eleman ekle \n");
        printf("2. Eleman sil \n");
        printf("3. Eleman ara \n");
        printf("4. Diziyi yazdir \n");
        printf("0. Cikis \n");
        printf("Seciminiz : ");
        scanf("%d", &choice);
        
        switch(choice) {
        	case 1:
        		printf("Eklemek istediginiz sayiyi girin: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Silmek istediginiz sayiyi girin: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                printf("Aradiginiz sayiyi girin: ");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                printArray();
                break;
            case 0:
                printf("Cikis yapiliyor...\n");
                break;
            default:
                printf("Hatali secim, tekrar deneyin!\n");
		}
	}while (choice != 0);

    return 0;
}
