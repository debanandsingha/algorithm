#include<stdio.h>

int partition(int [], int, int);
void quickSort(int [], int, int);
void readArray(int [], int);
void printArray(int [], int);
void swap(int *, int *);


void main(){

    int arr[10], size;
    
    printf("Enter size of the array: ");
    scanf("%d",&size);

    readArray(arr,size);
    printf("Before Sorting: ");
    printArray(arr,size);

    // partition(arr, 0, size-1);
    // printf("After Partitioning: ");
    // printArray(arr, size);
    quickSort(arr, 0, size-1);
    printf("After Sorting: ");
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

int partition(int arr[], int lb, int ub){

    int pivot, i, j;
    pivot=arr[lb];
    i=lb+1;
    j=ub;

    while (i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }

        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
    // if(i>j){
        swap(&arr[lb], &arr[j]);     
    // }
    return j;
}

void quickSort(int arr[], int lb, int ub){
    int loc;
    if(lb<ub){
        loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc-1);
        quickSort(arr, loc+1, ub);
    }
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}