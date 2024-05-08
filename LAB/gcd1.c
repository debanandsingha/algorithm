#include<stdio.h>

int gcd(int, int);
void swap(int *, int *);
void factors(int);

void main(){
    int arr[2];

    for(int i=0; i<2; i++){
        printf("Enter num%d: ", i+1);
        scanf("%d",&arr[i]);
    }

    for(int i=0; i<2; i++){
        printf("\nDivisors of %d are: ",arr[i]);
        factors(arr[i]);
    }
    printf("\nGCD of %d and %d is %d", arr[0], arr[1], gcd(arr[0], arr[1]));

}

// Euclidean algorithm
int gcd(int a, int b){
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
        if(num%i == 0)
            printf("%d ",i);
    }
}