//implement upper bound 
// condition: a[i] > x

#include <stdio.h>

int lowerBound(int arr[], int n, int x){
	int low = 0;
	int high = n - 1;
	int ans = n;
	while(low <= high){
		int mid = ( low + high )/2;
		//maybe an answer
		if(arr[mid] > x){
			ans = mid;
			//look for more smaller index in left 
			high = mid - 1;
		} else{
			low = mid + 1; //look for right;
		}
	}
	return ans;
}

int main() {
    int arr[] = {1, 3, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int ub = UpperBound(arr, n, target);

    printf("Upper Bound of %d is at index: %d\n", target, ub);

    return 0;
}
