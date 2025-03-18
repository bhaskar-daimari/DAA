#include <stdio.h>

#define MAX 10

void addEdge(int mat[MAX][MAX], int x, int i, int j, int size){
        mat[i][j] = x;
        mat[j][i] = x;
}

void displayMatrix(int mat[MAX][MAX], int size){
        for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                        printf("%d ", mat[i][j]);
                }
                printf("\n");
        }
}

int main(){
        int yes;
        int V1, V2, weight;
        printf("Enter the dimensions of the matrix: ");
        scanf("%d%d", &V1, &V2);
        int mat[MAX][MAX] = {};

        for(int i=0; i<V1; i++){
                for(int j=0; j<V2; j++){
                        printf("0 for FALSE and 1 for TRUE!\n");
                        printf("Does the vertices %d and %d have edges?: ", i, j);
                        scanf("%d", &yes);
                        if(yes){
                                printf("Please enter the weight of the edge between vertices %d and %d: ", i, j);
                                scanf("%d", &weight);
                                addEdge(mat, weight, i, j, V1);
                        }
                }
        }

        displayMatrix(mat, V1);
        return 0;
}
