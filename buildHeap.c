#include <stdio.h>

void buildMaxHeap(int *arr, int n, int i){
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
                buildMaxHeap(arr, n, max);
        }
}

int main(){
        int n, arr[50];
        printf("Enter the number of elements that you want: ");
        scanf("%d", &n);

        for(int i=0; i<n; i++){
                printf("Eneter the %dth element: ", i);
                scanf("%d", &arr[i]);
        }

        for(int i=n/2-1; i>=0; i--){
                buildMaxHeap(arr, n, i);
        }

        for(int i=0; i<n; i++){
                printf("%d\t", arr[i]);
        }
}
