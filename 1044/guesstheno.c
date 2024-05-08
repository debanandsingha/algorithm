/*
    Write a C program to implement the "Guess the Number" game, where the user thinks of a 
    secret number, and the program attempts to find the secret number by receiving x on 
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


void main(){

    int A[100], lb=1, ub=100,mid, x, count=1;;
        for(int i=1; i<=100; i++)
        A[i]=i;
    printf("Welcome to Guess the Number Game\n");
    printf("Think of any secret number between 1 to 100\n");
        while(lb<=ub){
        mid=(lb+ub)/2;

        printf("Is the secret number %d? (1: Too low, 2: Too high, 3: Correct): ",A[mid]);
        scanf("%d",&x);

        if(x==3){
            printf("Congratulations! The number %d is found in %d attempts.",A[mid],count);
            break;
        }
        if(x == 1)
            lb=mid+1;
        else if(x == 2)
            ub=mid-1;
        
        count++;
    }
}