//check if arr is sorted

#include <stdio.h>
#include <stdbool.h>

bool if_Sorted(int arr[], int n){
	for(int i = 1; i < n; i++){
		if(arr[i] >= arr[i - 1]){
			
		}
		else{
			return false;
		}
	}
	return true;
}

int main(){
	int n = 5;
	int arr[n];
	printf("Enter the Array: ");
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
    if (if_Sorted(arr, n)) {
        printf("The array is sorted.\n");
    } else {
        printf("The array is not sorted.\n");
    }
}
