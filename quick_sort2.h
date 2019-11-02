#include <stdio.h>

void quick_sort2(int * arr, int n);
void __quick_sort2(int * arr, int l, int r);
int __partition2(int * arr, int l, int r);

void quick_sort2(int * arr, int n) {
	__quick_sort2(arr, 0, n-1);
}

void __quick_sort2(int * arr, int l, int r) {
	if(l >= r) return;
	int p = __partition(arr, l, r);
	__quick_sort2(arr, l, p-1);
	__quick_sort2(arr, p+1, r);
}

int __partition2(int * arr, int l, int r) {
	int v = arr[l];
	int i = l+1;
	int j = r;
	while(1) {
		while(i<=r && arr[i] < v) i++;
		while(j>= l+1 && arr[j] > v) j--;
		if(i>j) break;
		swap(&arr[i], &arr[j]);
		i++;
		j--;
	}
	swap(&arr[l], &arr[j]);
	return j;
}
