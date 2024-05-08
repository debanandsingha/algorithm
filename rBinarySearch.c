#include<stdio.h>

void main(){

    int arr[10], size, lb, ub, key;
    printf("Enter size: ");
    scanf("%d",&size);
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);

    printf("Search: ");
    scanf("%d",&key);

    printf("Index: %d",bin(arr,0,size,key));
}

int bin(int arr[], int lb, int ub ,int key){

    int mid;

    if(lb<=ub){
        mid = (lb+ub)/2;
        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
            return bin(arr, lb, mid-1, key);
        else
            return bin(arr, mid+1, ub, key);
    }
}