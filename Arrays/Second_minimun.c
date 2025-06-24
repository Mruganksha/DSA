#include <stdio.h>
#include <math.h>
#include <limits.h>

int SecondSmallest(int arr[], int n){
	int min = arr[0];
	int secondMin = INT_MAX;
	for(int i = 1; i < n; i++){
		if(arr[i] < min){
			secondMin = min;
			min = arr[i];
		}
		else if(arr[i] > min && arr[i] < secondMin){
			secondMin = arr[i];
		}
	}
	return secondMin;
}

int main(){
	int n = 5;
	int arr[n];
	printf("Enter the Array: ");
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Second Largest element is : %d ", SecondSmallest(arr, n));
}
