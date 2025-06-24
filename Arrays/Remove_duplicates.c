//remove duplicates from sorted array 

#include <stdio.h>

int Remove_duplicates(int arr[], int n){
	int i = 0;
	for(int j = 1; j < n; j++){
		if(arr[j] != arr[i]){
			arr[i + 1] = arr[j];
			i++;
		}
	}
	for(int k = 0; k < (i+1); k++){
		printf("%d ", arr[k]);
		printf("\n");
	}
	return (i+1);
}

int main(){
	int n = 5;
	int arr[n];
	printf("Enter the Array: ");
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
    printf("count : %d ",Remove_duplicates(arr, n));
}
