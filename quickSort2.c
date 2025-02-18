#include <stdio.h>
void quickSort(int *arr, int p, int r);
int partition(int *arr, int p, int r);

int main(){
        //0accept adn array
        int arr[50], n;
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        printf("Enter the array elements:\n");
        for(int i=0; i<n; i++){
                printf("Element %d: ", i+1);
                scanf("%d", &arr[i]);
        }

        //calls quickSort function
        quickSort(arr, 0, n-1);

        //print the sorted array
        printf("The sorted array is:\n");
        for(int i=0; i<n; i++){
                printf("%d\t", arr[i]);
        }
}

//quickSort algo as a function
void quickSort(int *arr, int p, int r){
        if(p<r){
                int q = partition(arr, p, r);
                quickSort(arr, p, q-1);
                quickSort(arr, q+1, r);

        }
}

int partition(int *arr, int p, int r){
        int i=r+1;
        int x=arr[p];//taking the first element as the pivot
        for(int j=r; j>=0; j--){
                if(arr[j] > x){
                        i--;
                        int temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
                }
        }
        int temp = arr[p];
        arr[p] = arr[i-1];
        arr[i-1] = temp;
        return i-1;
}
