//next greater element
/* The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.*/


#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int* result = (int*)malloc(nums1Size * sizeof(int));
	
	for(int i = 0; i < nums1Size; i++){
		int found = 0;
		int j;
		for( j = 0; j < nums2Size; j++){
			if(nums2[j] == nums1[i]){
				found = 1;
				break;
			}
		}
		
		int nextGreater = -1;
		if(found){
			for(int k = j + 1; k < nums2Size; k++){
				if(nums2[k] > nums2[j]){
					nextGreater = nums2[k];
					break;
				}
			}
		}
		result[i] = nextGreater;
	}
	*returnSize = nums1Size;
	return result;
}

int main() {
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int returnSize;

    int* result = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}
