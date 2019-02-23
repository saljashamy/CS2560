#include <stdio.h>
#include "hw3.h"

int main(){
	geometryCalculator();

	sizePopulationYear();

	ticTacToeGame();

	int arr[5] = {1, 2, 3, 4, 5};
	printf("Array: ");
	for(int i = 0; i < 5; i++){
		printf("%d ", arr[i]);
	}
	putchar('\n');
	int *copyarr = reverseArray(&arr, 5);
	printf("Reverse copy array: ");
	for(int i = 0; i < 5; i++){
		printf("%d ", *(copyarr + i));
	}
}

