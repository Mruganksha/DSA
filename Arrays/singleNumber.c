//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

#include <stdio.h>

//brute force
int singleNumber(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }
        if (count == 1) {
            return nums[i];
        }
    }
    return -1; 
}


//optimal
//Using XOR (O(n) time, O(1) space)

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

