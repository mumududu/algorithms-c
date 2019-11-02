#include <stdio.h>

void quick_sort(int * arr, int n);
void __quick_sort(int * arr, int l, int r);
int __partition(int * arr, int l, int r);

void quick_sort(int * arr, int n) {
	__quick_sort(arr, 0, n-1);
}

void __quick_sort(int * arr, int l, int r) {
	if(l >= r) return;
	int p = __partition(arr, l, r);
	__quick_sort(arr, l, p-1);
	__quick_sort(arr, p+1, r);
}

int __partition(int * arr, int l, int r) {
	int v = arr[l];
	int j = l;
	for(int i=l+1;i<=r;i++) {
		if(arr[i] < v) {
			swap(&arr[i], &arr[j+1]);
			j++;
		}
	}
	swap(&arr[l], &arr[j]);
	return j;
}
