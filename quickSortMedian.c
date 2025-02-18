#include <stdio.h>
void quickSort(int *arr, int p, int r);
int partition(int *arr, int p, int r);

int main(){
        int arr[50], n;
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        printf("Enter the array element:");
        for(int i=0; i<n; i++){
                printf("Element %d: ", i+1);
                scanf("%d", &arr[i]);
        }
        quickSort(arr, 0, n-1);
        printf("The sorted array is:");
        for(int i=0; i<n; i++){
                printf(" %d", arr[i]);
        }
}

void quickSort(int *arr, int p, int r){
        if(p<r){
                int q = partition(arr, p, r);
                quickSort(arr, p, q-1);
                quickSort(arr, q+1, r);
        }
}

int partition(int *arr, int p, int r){
        int mid = (p - r)/2;
        int q;
        //choosing the median
        if(arr[p] < arr[mid] && arr[mid] < arr[r]){
                q = mid;
        }
        else if(arr[mid] > arr[p] && arr[r] < arr[p]){
                q = p;
        }
        else{
                q = r;
        }
        int temp = arr[r];
        arr[r] = arr[q];
        arr[q] = arr[r];
        int i=p-1;
        int x=arr[r];
        for(int j=p; j<=r; j++){
                if(arr[j] < x){
                        i++;
                        temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
                }
        }
        temp = arr[i+1];
        arr[i+1] = arr[r];
        arr[r] = temp;
        return i+1;
}
