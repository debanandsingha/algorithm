#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void swap(int *, int *);
void partition(int [], int, int);

void main(){
        int arr[10], size;
        printf("Enter size of the array: ");
        scanf("%d",&size);

        readArray(arr, size);
        printf("Entered elements: ");
        printArray(arr,size);

        partition(arr, 0, size-1);
        printf("After Partition1: ");
        printArray(arr, size);
}

void readArray(int arr[], int size){
        printf("Enter %d elements: ",size);
        for(int i=0; i<size; i++)
                scanf("%d",&arr[i]);
}
void printArray(int arr[], int size){
        for(int i=0; i<size; i++)
                printf("%d\t", arr[i]);
        printf("\n");
}

void swap(int *a, int *b){
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
}

// Taing 1st element as pivot element
void partition(int arr[], int lb,int ub){
        int i, j, p;
        i=lb;
        j=ub;
        p=arr[lb];

        while(i<j){
                while(arr[i]<=p)
                        i++;
                while(arr[j]>p)
                        j--;
                if(i<j)
                        swap(&arr[i], &arr[j]);
        }
        swap(&arr[lb], &arr[j]);
}
