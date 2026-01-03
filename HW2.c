#include <stdio.h>

void tower_of_hanoi(int n, int baslangicCubuk, int hedefCubuk, int gecici) {
    if (n == 0) {
        return;
    }
    
    tower_of_hanoi(n - 1, baslangicCubuk, gecici, hedefCubuk);
    
    printf("Diski %d: %d. cubuk -> %d. cubuk\n", n, baslangicCubuk, hedefCubuk);
    
    tower_of_hanoi(n - 1, gecici, hedefCubuk, baslangicCubuk);
}

int main() {
    tower_of_hanoi(3, 1, 3, 2);
    return 0;
}
/* Zaman denklemi su sekilde olur :
	S(n) = 2 × S(n-1) + O(1)  */

/* Buradan denklem
	S(n) = 2S(n-1) + 1
	S(n) = 2(2S(n-2)+ 1 + 1 = 4S(n-2) + 3
	S(n) = 2^kS(n-k)+(2^k-1)
	S(n) = 2^n -1 sonucuna ulasir.
	
	Time Complexity = O(2^n) olur*/
