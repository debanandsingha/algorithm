#include<stdio.h>

void main(){
    int num1, num2, gcd;

    printf("Enter num1: ");
    scanf("%d",&num1);
    printf("Enter num2: ");
    scanf("%d",&num2);

    printf("\nDivisors of %d are: ", num1);
    for(int i=1; i<= num1; i++){
        if(num1%i==0)
            printf("%d ",i);
    }
    printf("\nDivisors of %d are: ", num2);
    for(int i=1; i<= num2; i++){
        if(num2%i==0)
            printf("%d ",i);
    }

    for(int i=1; i<=num1 && i<= num2; i++){
        if(num1%i==0 && num2%i==0){
            gcd = i;
        }
    }

    printf("\nGCD of %d and %d is %d", num1, num2, gcd);
    
}