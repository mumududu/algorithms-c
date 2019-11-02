#include <stdlib.h>
void shellSort(int * arr, int n);

void shellSort(int * arr, int n) {
	// 首先确定对应的h值
	int h = 1;
	while(h<n/3) {
		h = h * 3 + 1;
	}

	while(h>=1) {
		// 使用h间距的插入排序
		for(int i=h;i<n;i++) {
			for(int j=i;j>=h && arr[j] < arr[j-h];j-=h) {
				swap(&arr[j], &arr[j-h]);
			}
		}
		h = h / 3;
	}
}
