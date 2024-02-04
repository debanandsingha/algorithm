/*
    Write a C program to implement the "Guess the Number" game, where the user thinks of a 
    secret number, and the program attempts to find the secret number by receiving feedback on 
    whether the guessed number is too low or too high. Ensure that your output matches the 
    provided format, and also make sure your program can handle any invalid inputs. 
    Output: 
    Welcome to Guess the Number Game 
    Think of any secret number between 1 to 100 
    Is the secret number 50? (1: Too low,2: Too high, 3: Correct): 2 
    ...
    Congratulations! The number 29 is found in 6 attempts.
*/

#include<stdio.h>

void guessTheNumber(int [], int , int );

void main(){

    int arr[100], lb=1, ub=100;

    printf("\nWelcome to Guess the Number Game\n");
    printf("Think of any secret number between 1 to 100\n\n");

    guessTheNumber(arr, lb, ub);
}

void guessTheNumber(int arr[], int lb, int ub){
    int mid, feedback, count=1;

    for(int i=1; i<=100; i++)
        arr[i]=i;

    while(lb<=ub){
        mid=(lb+ub)/2;

        printf("Is the secret number %d? ([1]: Too low, [2]: Too high, [3]: Correct): ",arr[mid]);
        scanf("%d",&feedback);

        if(feedback==3){
            printf("\n>> Congratulations! The number %d is found in %d attempts.\n\n",arr[mid],count);
            return;
        }
        if(feedback == 1)
            lb=mid+1;
        else if(feedback == 2)
            ub=mid-1;
        else
            printf(">> Invalid!\n");
        
        count++;
    }
}