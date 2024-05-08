#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void swap(int *, int *);
void sort(int [], int);
void main(){
    int arr[10], n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    readArray(arr, n);
    printArray(arr, n);

    sort(arr,n);
    printArray(arr,n);
}

void sort(int arr[], int n){
    //start from 2nd element which is the starting of unsorted list
    for(int i=1; i<n; i++){
        //take out the 1st element from the unsorted list
        //compare this element with the elements in sorted list
        int item=arr[i];

        //compare with sorted list decremented loop
        int j=i-1;  //last element of sorted list
        while(j>=0 && item<arr[j]){
            arr[j+1]=arr[j];    //right shift the element in sorted list (make space for the element to insert)
            j--;
        }
        arr[j+1]=item;  //insert element in its position
    }
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void readArray(int arr[], int n){
    printf("Enter %d elements: ",n);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
}

void printArray(int arr[], int n){
    printf("[ ");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("]\n");
}