#include <stdlib.h>

int* reverseArray(int arr[], int size){
	int *copy = malloc(sizeof(int) * size);
	for(int i = 0; i < size; i++){
		*(copy + i) = arr[size - 1 -i];
	}
	return copy;
}
