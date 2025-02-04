#include <stdio.h>

int main(){
        int d1, d2, d3;
        int A[10], B[10], C[10];

        // Inputing first polynomial
        printf("Enter the degree of the first polynomial: ");
        scanf("%d", &d1);
        printf("Enter the first polynomial\n");
        for(int i=0; i<=d1; i++){
                printf("Enter the coeffecient of x^%d: ", i);
                scanf("%d", &A[i]);
        }

        // Inputing second polynomial
        printf("Enter the degree of the second polynomial: ");
        scanf("%d", &d2);
        printf("Enter the second polynomial\n");
        for(int i=0; i<=d2; i++){
                printf("Enter the coefficient of x^%d: ", i);
                scanf("%d", &B[i]);
        }

        // Assigning highest power of the resultant polynomial
        if(d1 > d2){
                d3 = d1;
        }
        else{
                d3 = d2;
        }

        // Adding the two polynomials
        int i=0, j=0, k=0;
        while(i<=d1 && j<=d2){
                C[k++] = A[i++] + B[j++];
        }
        if(i>d1){
                while(j<=d2){
                        C[k++] = B[j++];
                }
        }
        if(j>d2){
                while(i<=d1){
                        C[k++] = A[i++];
                }
        }

        // Printing the added polynomial
        printf("The added polynomial is:\n");
        printf("%dx^%d", C[0], 0);
        for(int i=1; i<=d3; i++){
                printf("+%dx^%d", C[i], i);
        }
}
