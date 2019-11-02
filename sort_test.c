#include <stdio.h>
#include <string.h>
#include "sort_test_helper.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "quick_sort2.h"
#include "shell_sort.h"

void selectionSort(int * arr, int n);
void insertionSort(int * arr, int n);
int * mem_cpy(int * arr, int n);

int main(void) {
	int n = 10000;
	int * arr = generateRandomArray(n, 0, n);
	// int * arr = generateNearlyOrderedArray(n, 100);
	int * arr2 = mem_cpy(arr, n);
	int * arr3 = mem_cpy(arr, n);
	int * arr4 = mem_cpy(arr, n);
	int * arr5 = mem_cpy(arr, n);
	int * arr6 = mem_cpy(arr, n);

	testSort("selectionSort", selectionSort, arr, n);
	testSort("insertionSort", insertionSort, arr2, n);
	testSort("mergeSort", mergeSort, arr3, n);
	testSort("quickSort", quick_sort, arr4, n);
	testSort("quickSort2", quick_sort2, arr5, n);
	testSort("shellSort", shellSort, arr6, n);

	free(arr);
	free(arr2);
	free(arr3);
	free(arr4);
	free(arr5);
	free(arr6);
}

int * mem_cpy(int * arr, int n) {
	int * dest = (int *) malloc(n * sizeof(int));
	for(int i=0;i<n;i++) {
		dest[i] = arr[i];
	}
	return dest;
}

/*
 * 选择排序
 */
void selectionSort(int * arr, int n) {
	for(int i=0;i<n;i++) {
		int minIndex = i;
		for(int j=i+1;j<n;j++) {
			if(arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(&arr[i], &arr[minIndex]);
	}
}

/*
 * 插入排序
 */
void insertionSort(int * arr, int n) {
	for(int i=1;i<n;i++) {
		int e = arr[i];
		int j;
		for(j=i;j>0 && arr[j-1] > e;j--) {
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
}
