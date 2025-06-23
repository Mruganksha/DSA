//Insertion sort : take an element and place it in its right position
//like if we have arr or 14 9 15 12 6 8 13
//1st see only 1 ele now that is fine now check 1st 2 elements 14 and 9 swap then see 3 ele 9 14 15, yes then check 9 14 15 12, then right shift and check one one and swap swap now 9 12 14 15 6 and now same
//time complexity: worst and avg: O(n sq)
//best: O(n) , if arr is already sorted it will not go only in while loop

#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int a[], int n){
	for(int i = 0; i <= n-1; i++){
		int j = i;
		while(j > 0 && a[j-1] > a[j]){
			swap(&a[j-1], &a[j]);
			j--;
		}
	}
}

int main(){
	int Arr[] = {2, 5, 8, 3, 1, 9};
    int n = sizeof(Arr) / sizeof(Arr[0]);

    InsertionSort(Arr, n);

    for (int i = 0; i < n; i++){
        printf("%d ", Arr[i]);
    }

    return 0;
} 
