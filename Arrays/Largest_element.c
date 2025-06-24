//Largest element in array

#include <stdio.h>

int Largest_element(int arr[], int n){
	int max = arr[0];
	for(int i = 0; i < n; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

int main(){
	int n = 5;
	int arr[n];
	printf("Enter the Array: ");
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Largest element is : %d ", Largest_element(arr, n));
}
