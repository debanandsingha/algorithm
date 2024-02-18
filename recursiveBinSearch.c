#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
int rBinSearch(int [], int, int, int);
void bubbleSort(int [], int);
void swap(int *, int*);

void main(){
    int arr[10], size, lb, ub, key, loc;
    printf("Enter size of array: ");
    scanf("%d",&size);

    readArray(arr,size);
    printArray(arr,size);
    bubbleSort(arr, size);

    printf("After Sorting.. \n");
    printArray(arr,size);

    printf("Enter key to search: ");
    scanf("%d",&key);

    loc=rBinSearch(arr, 0, size, key);

    if(key == arr[loc])
        printf("Element %d is found at position %d.", key, loc+1);
    else
        printf("Element %d is not found in the array.", key);
    
}

void readArray(int arr[], int size){
    printf("Enter %d elements: ",size);
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);
}
void printArray(int arr[], int size){
    printf("Array elements: ");
    for(int i=0; i<size; i++)
        printf("%d\t",arr[i]);

    printf("\n");
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size){
    int i, j;
    for(i=0; i<size; i++){
        for(j=i+1; j<size; j++){
            if(arr[i]>arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
    
}

int rBinSearch(int arr[], int lb, int ub, int key){
    int mid;
    if(lb<=ub){
        mid  = (lb+ub)/2;

        if(key == arr[mid])
            return mid;
        else if(key<arr[mid])
            return rBinSearch(arr, lb, mid-1, key);
        else
             return rBinSearch(arr, mid+1, ub, key);
    }
}
