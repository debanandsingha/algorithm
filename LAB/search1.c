#include<stdio.h>
void BinarySearch(int [], int);
void swap(int *, int*);
void linearSearch(int [], int);
void main(){

    int A[10], n, i, j, x;
    char ch;

    printf("Enter number of Elements: ");
    scanf("%d",&n);
    
    printf("Enter %d elements: ",n);
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    printf("Elements: ",n);
    for(int i=0; i<n; i++)
        printf("%d\t",A[i]);

    printf("1: Linear Search 2: Binary Search ): ");
    scanf("%d",&x);

    switch (x)
    {
    case 1:
        while(ch != 'n'){
            linearSearch(A, n);
            printf("\n\nDo you want to search again? (y/n): ");
            scanf("%s",&ch);
        }
        break;
    case 2:
        while(ch != 'n'){
            
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                if(A[i]>A[j]){
                    swap(&A[i], &A[j]);
                }
            }
        }
        printf("Elements: ",n);
        for(int i=0; i<n; i++)
        printf("%d\t",A[i]);

        BinarySearch(A, n);

        printf("\n\nDo you want to search again? (y/n): ");
        scanf("%s",&ch);
        }
        break;
        }
    
    }


void linearSearch(int A[], int n){
    int key;
    printf("Enter Element to search: ");
    scanf("%d",&key);

    for(int i=0; i<n; i++){
        if(key==A[i]){
            printf("Element Found!");
            return;
        }
    }
        printf("Element Not Found!!");
}


    void BinarySearch(int A[], int n){
    int key, lb=0, ub=n, mid;

    printf("Enter the key value to search: ");
    scanf("%d",&key);

    while(lb <= ub){
        mid = (lb+ub)/2;
        if(key == A[mid]){
            printf("Yes, the number %d is found at position %d.", key, mid+1);
            return;
        }
        if(key < A[mid]){
            ub = mid-1;
        }else{
            lb = mid+1;
        }
    }
    printf("No, the number %d is not found in the Aay.", key);
}

void swap(int *a,int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}