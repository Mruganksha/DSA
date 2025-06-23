//recursive insertin sort
//If we take a closer look at Insertion Sort algorithm, we keep processed elements sorted and insert new elements one by one in the sorted array.
//Recursion Idea. 
//Base Case: If array size is 1 or smaller, return.
//Recursively sort first n-1 elements.
//Insert last element at its correct position in sorted array.

void InsertionSort(int arr[], int n){
	//base case
	if (n <= 1){
		return;
	}
	
	//sort 1st n-1 elements
	InsertionSort(arr, n-1);
	
	//insert last element at its correct position in sorted arr
	int last = arr[n - 1];
	int j = n - 2;
	
	 /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main() {
    int arr[] = {5, 2, 9, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
