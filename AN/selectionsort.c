#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void selectionSort(int [], int);
void swap(int *, int *);

void main(){
        int arr[10], n;
        printf("Enter size of array: ");
        scanf("%d",&n);

        readArray(arr, n);
        printf("Before Sorting: ");
        printArray(arr, n);

        selectionSort(arr,n);

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

void swap(int *a, int *b){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

void selectionSort(int arr[], int size){
	int i, j;
	for(j=0; j<n-1; j++)
}
