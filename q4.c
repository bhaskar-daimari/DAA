#include <stdio.h>

void sort(int *arr, int n);
void linearSearch(int *arr, int size, int target);
void binarySearch(int *arr, int size, int target);

int main(){
        int search;
        int size, target, arr[20];
        char flag;
        printf("Enter the length of the array: ");
        scanf("%d", &size);
        while(size > 20 || size < 0){
                printf("The size is invalid!\n");
                printf("Enter the length of the array: ");
                scanf("%d", &size);
        }
        for(int i=0; i<size; i++){
                printf("Element %d: ", i+1);
                scanf("%d", &arr[i]);
        }
        do{
                printf("Enter the key to search: ");
                scanf("%d", &target);
                printf("What searching technique do you want to use? (1 - Linear Search, 2 - Binary Search). ");
                scanf("%d", &search);
                while(search != 1 && search != 2){
                    printf("Enter a valid input.\n");
                    printf("What searching technique do you want to use? (1 - Linear Search, 2 - Binary Search). ");
                    scanf("%d", &search);
                }
                if(search == 1){
                    linearSearch(arr, size, target);
                }
                else if(search == 2){
                    sort(arr, size);
                    binarySearch(arr, size, target);
                }
                printf("Do you want to search again? (y/n): ");
                scanf(" %c", &flag);
        }while(flag == 'y' || flag == 'Y');
        return 0;
}

void sort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j>0; j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else{
                break;
            }
        }
    }
}

void linearSearch(int *arr, int size, int target){
        for(int i =0; i<size; i++){
                if(arr[i] == target){
                        printf("Yes, the number %d is found at position %d.\n", target, i+1);
                        return;
                }
        }
        printf("No, the number %d is not found in the array.\n", target);
}

void binarySearch(int *arr, int size, int target){
    printf("Binary Search being used\n");
    int mid, start = 0, end = size-1;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(target == arr[mid]){
            printf("Yes, the number %d is found at position %d.\n", target, mid+1);
            return;
        }
        else if(target < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    printf("No, the number %d is not found in the array.\n", target);
}