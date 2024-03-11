#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void selectionSort(int [], int);
void swap(int *, int *);

void main(){

    int arr[10], size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    readArray(arr, size);
    printf("Array: ");
    printArray(arr,size);

    selectionSort(arr,size);
    printf("Sorted array:\t");
    printArray(arr,size);

}

void selectionSort(int arr[], int size){
    int i, j, min_loc;
    for(i=0; i<size-1; i++){
        min_loc = i;

    // printf("%d", min_loc);
        for(j=i+1; j<size; j++){
            if(arr[j]<arr[min_loc])
                min_loc=j;
            // printf("%d\t",j);
        }

        // printf("\size");

        if(min_loc != i){
           swap(&arr[i], &arr[min_loc]);
        }
    }
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

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
