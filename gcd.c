#include<stdio.h>

int gcd(int, int);
void swap(int *, int *);
void factors(int);

// int count=0;    //Check recursive calls
void main(){
    // int num1, num2;
    int arr[2];
    
    // printf("Enter num1: ");
    // scanf("%d",&num1);
    // printf("Enter num2: ");
    // scanf("%d",&num2);

    for(int i=0; i<2; i++){
        printf("Enter num%d: ", i+1);
        scanf("%d",&arr[i]);
    }

    // if(num1<num2)
    //     swap(&num1, &num2);
    // printf("Divisors of %d are: ",num1);
    // factors(num1);

    for(int i=0; i<2; i++){
        printf("\nDivisors of %d are: ",arr[i]);
        factors(arr[i]);
    }
    printf("\nGCD of %d and %d is %d", arr[0], arr[1], gcd(arr[0], arr[1]));
    // printf("\nRecursive call: %d",count);

}

// Euclidean algorithm
int gcd(int a, int b){
    // count ++;
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void factors(int num){
    for(int i=1; i<=num; i++){
        //A factor is an integer that fully divides another integer.
        if(num%i == 0)
            printf("%d ",i);
    }
}