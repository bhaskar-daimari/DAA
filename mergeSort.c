#include <stdio.h>

void merge2Sorted(int *arr, int low, int mid, int high);
void mergeSort(int *arr, int lb, int ub);


int main(){
        int n, index;
        int arr[50];
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        printf("Enter the array elements:\n");
        for(int i=0; i<n; i++){
                printf("Element %d: ", i+1);
                scanf("%d", &arr[i]);
        }
        printf("Enter the index where the highest element should be inserted: ");
        scanf("%d", &index);
        while(index < 1 || index >= n){
                printf("The index that you provided is invalid!\n");
                printf("Please enter a valid index: ");
                scanf("%d", &index);
        }
        mergeSort(arr, 0, n-1);
        int temp = arr[index-1];
        arr[index-1] = arr[n-1];
        arr[n-1] = temp;
        mergeSort(arr, 0, index-2);
        mergeSort(arr, index, n-1);
        for(int i=0; i<n; i++){
                printf("%d\t", arr[i]);
        }
}

void merge2Sorted(int *arr, int low, int mid, int high){
        int size1 = mid - low + 1;
        int size2 = high - mid;
        int L[size1], R[size2];
        for(int i = 0; i<size1; i++){
                L[i] = arr[low + i];
        }
        for(int i = 0; i<size2; i++){
                R[i] = arr[mid + 1 + i];
        }
        int i=0, j=0, k=low;
        while(i<size1 && j<size2){
                if(L[i] <= R[j]){
                        arr[k++] = L[i++];
                }
                else{
                        arr[k++] = R[j++];}
        }
        if(i>=size1){
                while(j<size2){
                        arr[k++] = R[j++];
                }
        }
        else if(j>=size2){
                while(i<size1){
                        arr[k++] = L[i++];
                }
        }
}

void mergeSort(int *arr, int lb, int ub){
        if(lb < ub){
                int mid = lb + (ub - lb)/2;
                mergeSort(arr, lb, mid);
                mergeSort(arr, mid+1, ub);
                merge2Sorted(arr, lb, mid, ub);
        }
}