#include <stdio.h>

//This function makes a max heap
void heapify(int *arr, int n, int i){
        int max = i;
        int leftIndex = 2*i+1;
        int rightIndex = 2*i+2;
        if(leftIndex<n && arr[max] < arr[leftIndex]){
                max = leftIndex;
        }
        if(rightIndex<n && arr[max] < arr[rightIndex]){
                max = rightIndex;
        }
        if(max != i){
                int temp = arr[i];
                arr[i] = arr[max];
                arr[max] = temp;
                heapify(arr, n, max); //Recursively calling the build heap function for the lower parts after the swap
        }
}

void buildMaxHeap(int *arr, int n){
        for(int i=n/2-1; i>=0; i--){
                heapify(arr, n, i);
        }
}

void heapSort(int *arr, int n){
        buildMaxHeap(arr, n);
        for(int i=n-1; i>0; i--){
                int temp = arr[0];
                arr[0] = arr[i];
                arr[i] = temp;
                heapify(arr, i, 0);
        }
}

int main(){
        int n, arr[50];

        printf("How many elements do you want to enter: "); //Take input of the size of the array
        scanf("%d", &n);

        for(int i=0; i<n; i++){ //Inputs the array elements by the user
                printf("Enter the %dth element: ", i);
                scanf("%d", &arr[i]);
        }

        heapSort(arr, n);

        for(int i=0; i<n; i++){ //Prints the array elements
                printf("%d\t", arr[i]);
        }
}
