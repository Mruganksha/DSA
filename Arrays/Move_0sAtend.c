//move all 0s at the end

#include <stdio.h>

//optimal approach
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes(int* nums, int numsSize) {
    int j = -1;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            j = i;
            break;
        }
    }
    
    if(j == -1) return;

    for(int i = j + 1; i < numsSize; i++){
        if(nums[i] != 0){
            swap(&nums[i], &nums[j]);
            j++;
        }
    }
}
