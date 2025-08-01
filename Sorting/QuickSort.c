//Quick Sort:
//TimeComplexity: O(nlog(n))
//spaceComplexity: O(1)

//pick a pivot , place it in its correct place in the sorted arr
//pivot here will be the 1st or last or median(idle) element , then smaller on the left and larger on right

#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
	//choose pivot
	int pivot = arr[high];
	 // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements to the left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

void QuickSort(int arr[], int low, int high){
	if(low < high){
		 
        // pi is the partition return index of pivot
		int pi = partition(arr, low, high);
		
		//recursion calls for smaller elements and greater or equal elements
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
