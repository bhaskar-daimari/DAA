#include <stdio.h>

void merge(int *A, int *B, int *Merge, int ub1, int ub2, int ub);

int main(){
        int A[15],  B[15], C[30];
        int ub1, ub2, ub;
        printf("Enter the size of the first Array: ");
        scanf("%d", &ub1);
        printf("Enter the array elements of the first Array:\n");
        for(int i=0; i<ub1; i++){
                printf("ELement %d: ", i+1);
                scanf("%d", &A[i]);
        }
        printf("Enter the size of the second Array: ");
        scanf("%d", &ub2);
        printf("Enter the array elements of the second Array:\n");
        for(int i=0; i<ub2; i++){
                printf("Element %d: ", i+1);
                scanf("%d", &B[i]);
        }
        ub = ub1+ub2;
        merge(A, B, C, ub1, ub2, ub);
        printf("The merged array is:\n");
        for(int i=0; i<ub; i++){
                printf("%d\t", C[i]);
        }
}

void merge(int *A, int *B, int *Merge, int ub1, int ub2, int ub){
        int i=0, j=0, k=0;
        while(i<ub1 && j<ub2){
                if(A[i] < B[j]){
                        Merge[k++] = A[i++];
                }
                else{
                        Merge[k++] = B[j++];
                }
        }
        if(i>=ub1){
                while(j<ub2){
                        Merge[k++] = B[j++];
                }
        }
        if(j>=ub2){
                while(i<ub1){
                        Merge[k++] = A[i++];
                }
        }
}
