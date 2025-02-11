#include <stdio.h>

int partition(int *arr, int low, int high);
void quickSort(int *arr, int low, int high);

int main(){
        int arr[50];
        int n;
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        printf("Enter the array elements:\n");
        for(int i=0; i<n; i++){
                printf("Element %d: ", i+1);
                scanf("%d", &arr[i]);
        }
        quickSort(arr, 0, n-1);
        for(int i=0; i<n; i++){
                printf("%d\n", arr[i]);
        }
}


int partition(int *arr, int low, int high){
        int x = arr[high];
        int i = low - 1;
        for(int j=low; j<=high; j++){
                if(arr[j] < x){
                        i++;
                        int temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
                }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        return i+1;
}

void quickSort(int *arr, int low, int high){
        if(low < high){
                int mid = partition(arr, low, high);
                quickSort(arr, low, mid - 1);
                quickSort(arr, mid + 1, high);
        }
}