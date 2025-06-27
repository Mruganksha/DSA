#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Hash map node
typedef struct Node {
    int sum;
    int index;
    struct Node* next;
} Node;

Node* hashTable[MAX];

// Hash function
int hash(int key) {
    if (key < 0) key = -key;
    return key % MAX;
}

// Insert into hash map (only first occurrence)
void insert(int sum, int index) {
    int h = hash(sum);
    Node* temp = hashTable[h];
    while (temp) {
        if (temp->sum == sum)
            return; // Already exists
        temp = temp->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

// Search in hash map
int search(int sum) {
    int h = hash(sum);
    Node* temp = hashTable[h];
    while (temp) {
        if (temp->sum == sum)
            return temp->index;
        temp = temp->next;
    }
    return -1;
}

// Function to find longest subarray with sum K
int longestSubarrayWithSumK(int arr[], int n, int K) {
    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < MAX; i++) hashTable[i] = NULL;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == K)
            maxLen = i + 1;

        int rem = sum - K;
        int index = search(rem);
        if (index != -1)
            if (i - index > maxLen)
                maxLen = i - index;

        insert(sum, i);
    }

    return maxLen;
}

int main() {
    int arr[] = {1, -1, 5, -2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 3;

    int result = longestSubarrayWithSumK(arr, n, K);
    printf("Length of longest subarray with sum %d is %d\n", K, result);

    return 0;
}

