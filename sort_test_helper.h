#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
int * generateRandomArray(int n, int rangeL, int rangeR);
void testSort(char* sortName, void(*sort) (int[], int), int arr[], int n);
int isSorted(int arr[], int n);
int * generateNearlyOrderedArray(int n, int swapTimes);
void swap(int * a, int * b);

int * generateRandomArray(int n, int rangeL, int rangeR) {
	assert(rangeL <= rangeR);
	int * arr = (int *)malloc(n * sizeof(int));
	srand((unsigned) time(NULL));
	for(int i=0;i<n;i++) {
		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	}
	return arr;
}

int * generateNearlyOrderedArray(int n, int swapTimes) {
	int *arr = (int *) malloc(n * sizeof(int));
	for(int i=0;i<n;i++) {
		arr[i] = i+1;
	}
	srand((unsigned) time(NULL));
	for(int i=0;i<swapTimes;i++) {
		int posx = rand()%n;
		int posy = rand()%n;
		swap(&arr[posx], &arr[posy]);
	}
	return arr;
}

void swap(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void testSort(char* sortName, void(*sort) (int[], int), int arr[], int n) {
	clock_t startTime = clock();
	sort(arr, n);
	clock_t endTime = clock();
	assert(isSorted(arr, n));
	printf("%s : %.4lfs\n", sortName, (double)(endTime-startTime)/CLOCKS_PER_SEC);
}

int isSorted(int arr[], int n) {
	for(int i=1;i<n;i++) {
		if(arr[i-1] > arr[i]) {
			return 0;
		}
	}
	return 1;
}
