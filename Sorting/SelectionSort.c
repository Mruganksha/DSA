#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int Arr[], int n){
    for(int i = 0; i <= n - 2; i++){
        int mini = i;
        for(int j = i + 1; j < n; j++){
            if(Arr[j] < Arr[mini]){
                mini = j;
            }
        }
        swap(&Arr[mini], &Arr[i]);
    }
}

int main(){
    int Arr[] = {2, 5, 8, 3, 1, 9};
    int n = sizeof(Arr) / sizeof(Arr[0]);

    SelectionSort(Arr, n);

    for (int i = 0; i < n; i++){
        printf("%d ", Arr[i]);
    }

    return 0;
}

