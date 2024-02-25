#include<stdio.h>

void partition(int [], int, int);
void readArray(int [], int);
void printArray(int [], int);
void swap(int *, int *);

void main(){
    int arr[10], size;
    
    printf("Enter size of the array: ");
    scanf("%d",&size);

    readArray(arr,size);
    printf("Array Elements:\t");
    printArray(arr,size);

    partition(arr, 0, size-1);
    printf("After Partitioning:\t");
    printArray(arr, size);
}

void readArray(int arr[], int size){
    printf("Enter %d elements: ",size);
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);
}
void printArray(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%d\t",arr[i]);

    printf("\n");
}

void partition(int arr[], int lb, int ub){

    int pivot, i, j;
    pivot=arr[ub];
    i=lb-1;
    j=lb;

    while (j<ub){
       if(arr[j] <= pivot){
        i++;
        swap(&arr[i], &arr[j]);
       }
       j++;
    }
    swap(&arr[i+1], &arr[j]);     
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}