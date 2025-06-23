//Recursive bubbleSort
//Base Case: If array size is 1, return.
//Do One Pass of normal Bubble Sort. This pass fixes last element of current subarray.
//Recur for all elements except last of current subarray

#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[], int n){
	//base case 
	if(n == 1){
		return;
	}
	
	int count = 0;
	//after this pass. largest element is moved to end
	for(int i = 0; i < n-1; i++){
		if(arr[i] > arr[i+1]){
			swap(&arr[i], &arr[i+1]);
			count++;
		}
    }
		//if no recursion then return
		if (count == 0){
			return;
		}
	BubbleSort(arr, n- 1);
}

int main() {
    int arr[] = {5, 2, 9, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

