#include <stdio.h>
//rotate by d spcae


//brute force approach
void leftRotate(int arr[], int n, int d){
	d = d % n;
	int temp[d];
	for(int i = 0; i < d; i++){
		temp[i] = arr[i];
	}
	for(int i = d; i < n; i++){
		arr[i - d] = arr[i];
	}
	for(int i = n - d; i < n; i++){
		arr[i] = temp[i - (n - d)];
	}
}


//optimal approach
void reverse(int* nums, int start, int end){
    while(start <= end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void Rightrotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

void leftrotate(int* nums, int numsSize, int k){
	k = k % numsSize;
	// Reverse first k elements
    reverse(nums, 0, k - 1);
    // Reverse remaining n - k elements
    reverse(nums, k, numsSize - 1);
    // Reverse the whole array
    reverse(nums, 0, numsSize - 1);
}
