#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void swap(int *, int *);
void heapSort(int[], int);
void buildMaxHeap(int [], int);
void heapify(int [], int, int);

void main(){
    int arr[10], size;

    printf("Enter size of the array: ");
    scanf("%d",&size);

    readArray(arr, size);
    printf("Array: ");
    printArray(arr,size);

    heapSort(arr,size);
    printf("Sorted array:\t");
    printArray(arr,size);
}

void heapSort(int arr[], int size){
    int j=size-1;
    if(size>0){
        buildMaxHeap(arr,size);
        swap(&arr[0], &arr[j]);
        j--;
        heapSort(arr, size-1);
    }
}

void buildMaxHeap(int arr[], int size){
    for(int i=size/2; i>=0; i--){
        heapify(arr,i,size);
    }
}

void heapify(int arr[], int i,int size){
    int l, r, max;
    l=(2*i)+1;
    r=l+1;

    if(l<size && arr[l]>arr[i])
        max=l;
    else
        max=i;
    
    if(r<size && arr[r]>arr[max])
        max=r;
    
    if(max != i){
        swap(&arr[max], &arr[i]);
        heapify(arr, max, size);
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