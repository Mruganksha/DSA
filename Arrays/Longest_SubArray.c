//largest subarray of sum k

#include <stdio.h>


//using 2 pointer approach but it is only suitable for non negative elements
int longestSubarrayWithSumK(int arr[], int n, int K) {
    int start = 0, end = 0;
    int sum = 0, maxLen = 0;

    while (end < n) {
        sum += arr[end];

        // Shrink the window until sum <= K
        while (sum > K && start <= end) {
            sum -= arr[start];
            start++;
        }

        // Check if sum == K
        if (sum == K) {
            int len = end - start + 1;
            if (len > maxLen)
                maxLen = len;
        }

        end++;
    }

    return maxLen;
}

int main() {
    int arr[] = {1, 2, 1, 1, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 5;

    int result = longestSubarrayWithSumK(arr, n, K);
    printf("Length of longest subarray with sum %d is %d\n", K, result);

    return 0;
}

