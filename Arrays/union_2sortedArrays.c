#include <stdio.h>

void printUnion(int A[], int n, int B[], int m) {
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (A[i] < B[j]) {
            printf("%d ", A[i++]);
        }
        else if (A[i] > B[j]) {
            printf("%d ", B[j++]);
        }
        else {
            // Both elements are same
            printf("%d ", A[i]);
            i++;
            j++;
        }

        // Skip duplicates in A
        while (i > 0 && i < n && A[i] == A[i - 1]) i++;
        // Skip duplicates in B
        while (j > 0 && j < m && B[j] == B[j - 1]) j++;
    }

    // Print remaining elements of A
    while (i < n) {
        printf("%d ", A[i]);
        while (i + 1 < n && A[i] == A[i + 1]) i++;
        i++;
    }

    // Print remaining elements of B
    while (j < m) {
        printf("%d ", B[j]);
        while (j + 1 < m && B[j] == B[j + 1]) j++;
        j++;
    }

    printf("\n");
}

int main() {
    int A[] = {1, 2, 4, 5, 6};
    int B[] = {2, 3, 5, 7};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    printf("Union of the arrays is: ");
    printUnion(A, n, B, m);

    return 0;
}

