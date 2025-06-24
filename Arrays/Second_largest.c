#include <stdio.h>

int SecondLargest(int arr[], int n){
	int max = arr[0];
	int secondMax = -1;
	for(int i = 1; i < n; i++){
		if(arr[i] > max){
			secondMax = max;
			max = arr[i];
		}
		else if(arr[i] < max && arr[i] > secondMax){
			secondMax = arr[i];
		}
	}
	return secondMax;
}

int main(){
	int n = 5;
	int arr[n];
	printf("Enter the Array: ");
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Second Largest element is : %d ", SecondLargest(arr, n));
}
