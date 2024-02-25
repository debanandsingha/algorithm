#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void bubbleSort(int [], int);
void swap(int *, int *);

void main(){
    int arr[10], n;
    
    printf("Enter size of the array: ");
    scanf("%d",&n);

    readArray(arr, n);
    printf("Before Sorting: ");
    printArray(arr, n);

    bubbleSort(arr, n);
    printf("After Sorting: ");
    printArray(arr, n);

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

void bubbleSort(int arr[], int size){
    int i, j, flag=1;
    for(i=0; i<size-1 && flag==1; i++){
        flag=0;
        for(j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                flag=1;
            }
        }
    }
    
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}