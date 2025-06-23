//adjacent swaps check 1st 2 swao, then next 2 and so on
//step 1 : 0 to n-1 then 2nd time 0 - n-2; and so on
//time complexity : worst and avg case: o(n sq)
//best is o(n)
#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int a[], int n){
	for(int i = n - 1; i >= 0; i--){
		int didSwap = 0;
		for(int j = 0; j <= i -1; j++){
			if(a[j] > a[j + 1]){
				swap(&a[j], &a[j + 1]);
				didSwap = 1;
			}
		}
		if(didSwap == 0){
			break;
		}
	}
}

int main(){
	int Arr[] = {2, 5, 8, 3, 1, 9};
    int n = sizeof(Arr) / sizeof(Arr[0]);

    BubbleSort(Arr, n);

    for (int i = 0; i < n; i++){
        printf("%d ", Arr[i]);
    }

    return 0;
}
