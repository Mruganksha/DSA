//missing element in an array
//Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 
#include <stdio.h>

//brute force approach
int findMissingBrute(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            return i;  
        }
    }
    return -1;  
}

//xor approach (optimal)
int findMissing(int arr[], int n) {
    int xorAll = 0;
    int xorArr = 0;
    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xorAll ^= i;
    }
    // XOR all elements in the array
    for (int i = 0; i < n - 1; i++) {
        xorArr ^= arr[i];
    }
    // Missing number is xorAll ^ xorArr
    return xorAll ^ xorArr;
}

//using sum (optimal sol)
int missingNumber(int* nums, int numsSize) {
    int sum = (numsSize*(numsSize + 1))/2;
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        count = count + nums[i];
    }
    int result = sum - count;
    return result;
}

int main() {
    int arr[] = {1, 2, 4, 5};
    int n = 5;

    int missing = findMissing(arr, n);
    printf("Missing number is: %d\n", missing);

    return 0;
}
