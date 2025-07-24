//next greater element using stack

#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* nextGreater = (int*)malloc(nums2Size * sizeof(int));
    int* result = (int*)malloc(nums1Size * sizeof(int));
    int stack[nums2Size];
    int top = -1;

    for (int i = 0; i < nums2Size; i++) {
        nextGreater[i] = -1;
    }

    for (int i = 0; i < nums2Size; i++) {
        while (top != -1 && nums2[i] > nums2[stack[top]]) {
            nextGreater[stack[top]] = nums2[i];
            top--;
        }
        stack[++top] = i;
    }

    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                result[i] = nextGreater[j];
                break;
            }
        }
    }

    *returnSize = nums1Size;
    free(nextGreater);
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

