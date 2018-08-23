#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int part(int arr[], int left, int right) {

	// int rnd = rand() % (right - left + 1) + left;
	// swap(&arr[left], &arr[rnd]);  //for random pivot

	int pivot = arr[left];
	int i = left, j;
	for(j = left + 1; j <= right; j++) {
		if(pivot > arr[j]) {
			swap(&arr[j], &arr[++i]);
		}
	}

	swap(&arr[left], &arr[i]);

	return i;
}

void quickSort(int arr[], int left, int right) {
	if(left < right) {
		int pivot = part(arr, left, right);
		quickSort(arr, left, pivot-1);
		quickSort(arr, pivot+1, right);
	}
}

void printArray(int A[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main() {
    long int size = 10;
    int arr[size];
    
    for(int i=0; i<size; i++) {
        arr[i] = (rand() % (100 - 0 + 1)) + 0;
    }
 
    printf("Given array is \n");
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printf("\nSorted array is \n");
    printArray(arr, size);
    return 0;
}