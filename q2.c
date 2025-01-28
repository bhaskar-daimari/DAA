#include <stdio.h>

int main(){
        printf("Welcome to Guess the Number Game\n");
        printf("Think of any secret number between 1 to 100\n");
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
                        return 0;
                }
                i++;
        }while(low <= high);
        if(low > high){
                printf("You LOST\n");
                return 0;
        }
}
