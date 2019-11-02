#include <stdlib.h>
void mergeSort(int * arr, int n);
void __mergeSort(int * arr, int l, int r);
void __merge(int * arr, int l, int mid, int r);

void mergeSort(int * arr, int n) {
	__mergeSort(arr, 0, n-1);
}

/**
 * 对arr[l..r]的数据进行归并
 */
void __mergeSort(int * arr, int l, int r) {
	if(l >= r)
		return;
	int mid = (l+r)/2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);
	if(arr[mid] > arr[mid+1])
		__merge(arr, l, mid, r);
}

/**
 * 将arr[l...mid]和arr[mid+1...r]两部分进行归并
 */
void __merge(int * arr, int l, int mid, int r) {
	int * aux = (int *)malloc((r-l+1) * sizeof(int));
	for(int i=l;i<=r;i++) {
		aux[i-l] = arr[i];
	}
	int i = l;
	int j = mid+1;
	for(int k=l;k<=r;k++) {
		if(i>mid) {
			arr[k] = aux[j-l];
			j++;
		} else if(j>r) {
			arr[k] = aux[i-l];
			i++;
		} else if(aux[i-l] < aux[j-l]) {
			arr[k] = aux[i-l];
			i++;
		} else {
			arr[k] = aux[j-l];
			j++;
		}
	}

	free(aux);
}

