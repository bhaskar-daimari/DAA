#include <stdio.h>

void linearSearch(int *arr, int size, int target){
        for(int i =0; i<size; i++){
                if(arr[i] == target){
                        printf("Yes, the number %d is found at position %d.\n", target, i+1);
                        return;
                }
        }
        printf("No, the number %d is not found in the array.\n", target);
}

int main(){
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
                linearSearch(arr, size, target);
                printf("Do you want to search again? (y/n): ");
                scanf(" %c", &flag);
        }while(flag == 'y' || flag == 'Y');
        return 0;
}
