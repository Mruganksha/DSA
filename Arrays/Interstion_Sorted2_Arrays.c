//Intersection od 2 sorted arrays

#include <stdio.h>

//without duplicates
void printIntersection(int A[], int n, int B[], int m) {
    int i = 0, j = 0;

    while (i < n && j < m) {
        // Skip duplicates in A
        if (i > 0 && A[i] == A[i - 1]) {
            i++;
            continue;
        }
        // Skip duplicates in B
        if (j > 0 && B[j] == B[j - 1]) {
            j++;
            continue;
        }

        if (A[i] < B[j]) {
            i++;
        }
        else if (A[i] > B[j]) {
            j++;
        }
        else {
            // A[i] == B[j], common element
            printf("%d ", A[i]);
            i++;
            j++;
        }
    }

    printf("\n");
}


void printIntersectionDuplicate(int A[], int n, int B[], int m) {
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (A[i] < B[j]) {
            i++;
        }
        else if (A[i] > B[j]) {
            j++;
        }
        else {
            // A[i] == B[j] ? common element (include it)
            printf("%d ", A[i]);
            i++;
            j++;
        }
    }

    printf("\n");
}

int main() {
    int A[] = {1, 2, 2, 3, 4, 5};
    int B[] = {2, 2, 3, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    printf("Intersection of the arrays is: ");
    printIntersection(A, n, B, m);

    return 0;
}

