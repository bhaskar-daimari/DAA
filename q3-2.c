#include <stdio.h>

void linearSearch();
void binarySearch();


int main(){
        printf("Welcome to Guess the Number Game\n");
        printf("Think of any secret number between 1 to 100\n");
        printf("Enter 1 for Linear and 2 for Binary ");
        int algo;
        scanf("%d", &algo);
        while(algo != 1 && algo != 2){
            printf("Invalid Input Enter again");
            printf("Enter 1 for Linear and 2 for Binary ");
            scanf("%d", &algo);
        }
        if(algo == 1){
            linearSearch();
        }
        else if(algo == 2){
            binarySearch();
        }
}

void linearSearch(){
    int n;
    for(int i=0; i<100; i++){
        printf("Is the secrect number %d? ", i);
        printf("(1: Too Low, 2: Too high, 3: Correct): ");
        scanf("%d", &n);
        while(n<0 || n>3){
            printf("Invalid Input\nEnter again: ");
            scanf("%d", &n);
        }
        if(n == 3){
            printf("Congratulations! The number %d is found in %d attempts.\n", i, i+1);
            return;
        }
    }
    printf("You LOST\n");
}

void binarySearch(){
int n, i = 0, low = 0, high = 100, mid;
        do{
                mid = low + (high - low) / 2;
                printf("Is the secrect number %d? ", mid);
                printf("(1: Too Low, 2: Too high, 3: Correct): ");
                scanf("%d", &n);
                while(n<0 || n>3){
                        printf("Invalid Input\nEnter again: ");
                        scanf("%d", &n);
                }
                if(n == 1){
                        low = mid + 1;
                }
                else if(n == 2){
                        high = mid - 1;
                }
                else{
                        printf("Congratulations! The number %d is found in %d attempts.\n", mid, i+1);
                        return;
                }
                i++;
        }while(low <= high);
        if(low > high){
                printf("You LOST\n");
                return;
        }
}