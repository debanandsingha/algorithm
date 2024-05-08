#include<stdio.h>

int BinarySearch(int [], int, int, int);
void swap(int *, int*);

void main(){
    int A[10], n, lb, ub, key, loc, i, j;
    printf("Enetr size of array: ");
    scanf("%d",&n);

    printf("Enter %d elements: ",n);
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    printf("Elements: ",n);
    for(int i=0; i<n; i++)
        printf("%d\t",A[i]);

    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(A[i]>A[j]){
                swap(&A[i], &A[j]);
            }
        }
    }

        printf("After Sorting.. \n");
    printf("Array elements: ");
    for(int i=0; i<n; i++)
        printf("%d\t",A[i]);
        printf("Enter key to search: ");
    scanf("%d",&key);
    loc=BinarySearch(A, 0, n, key);
    printf("Element %d is found at position %d.", key, loc+1);
    
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int BinarySearch(int A[], int lb, int ub, int key){
    int mid;
    if(lb<=ub){
        mid  = (lb+ub)/2;

        if(key == A[mid])
            return mid;
        else if(key<A[mid])
            return BinarySearch(A, lb, mid-1, key);
        else
             return BinarySearch(A, mid+1, ub, key);
    }
}