#include <stdio.h>
#include <stdlib.h>

struct Element{
	int row;
	int col;
	int value;
};

struct SparseMatrix{
	int rows;
	int cols;
	int numElements;
	struct Element* elements;
};

//Sparse matrix olusturma kýsmý

struct SparseMatrix newSparseMatrix(int rows, int cols, int numElements){
	struct SparseMatrix s;
	s.rows = rows;
	s.cols = cols;
	s.numElements = numElements;
	s.elements = (struct Element*)malloc(numElements * sizeof(struct Element));
	return s;
}

//Ekrana yazdýrma

void printSparseMatrix(struct SparseMatrix s){
	int k = 0;
	for (int i=0; i<s.rows; i++){
		for(int j=0; j<s.cols; j++ ){
			if(k<s.numElements && s.elements[k].row==i && s.elements[k].col==j){
			printf("%d ", s.elements[k].value);
                k++;
			}else{
				printf("0");
			}
		}
		printf("\n");
	}
}

int main(){
	int rows, cols;
	
	printf("Matrisin satir sayisini girin: ");
    scanf("%d", &rows);
    printf("Matrisin sutun sayisini girin: ");
    scanf("%d", &cols);

    int** matrix = (int**) malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        matrix[i] = (int*) malloc(cols * sizeof(int));
    }

    printf("Matrisin elemanlarini girin (%d x %d):\n", rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int elemanSayisi = 0;
    for(int i=0; i<rows; i++){
    	for(int j=0; j<cols; j++){
    		if(matrix[i][j] !=0){
    			elemanSayisi++;
			}
		}
	}
	
	struct SparseMatrix s = newSparseMatrix(rows, cols, elemanSayisi);
	
	int k = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] != 0){
                s.elements[k].row = i;
                s.elements[k].col = j;
                s.elements[k].value = matrix[i][j];
                k++;
            }
        }
    }
    
	printf("\nSparse Matrix:\n");
    printSparseMatrix(s);
    
    for(int i = 0; i < rows; i++){
        free(matrix[i]);
    }
    free(matrix);
    free(s.elements);

    return 0;
    
    
}
