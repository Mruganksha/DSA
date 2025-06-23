//Merge sort
//Divide and merge
//if even then half half and odd then one will be n+1/2 and n/2 and divide it so on
//[3, 1, 2, 4, 1, 5, 2, 6, 4]
//1st ele is low and last is high
//[3, 1,2, 4, 1]   [5, 2, 6, 4]
//[3, 1, 2] + [4, 1]   [5, 2] + [6, 4]
//[3, 1] + 2   4 + 1    5 + 2    6 + 4
//3 + 1 
//now merge 3 and 1 in sorted way 1, 3 now nxt merge [1,3] and 2 then we will get [1, 2, 3]
//now compare it with 4 and 1
//when we compare left and right arr 1stly both in themself are sorted so compare 1st element of each and decide which will be 1st element in sorted arr and continue same way
//recursion and backtracking

#include <stdio.h>

void merge(int arr[], int low, int mid, int high){
	int i = low;
	int j = mid + 1;
	int k = 0;
	
	int temp[high - low + 1];
	
	while(i <= mid && j <= high){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		} else{
			temp[k++] = arr[j++];
		}
	}
	
	while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (int x = 0; x < k; x++) {
        arr[low + x] = temp[x];
    }
}

void MergeSort(int arr[], int low, int high){
   if(low >= high){
   	 return;
   }
   int mid = (low + high)/2;
   MergeSort(arr, low, mid);
   MergeSort(arr, mid + 1, high);
   merge(arr, low, mid, high);
}

int main() {
    int arr[] = {5, 2, 9, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

//TimeCoplexity: divide: log(n) + merge O(n) = nlog(n)
//SpaceComplexity: O(n)

