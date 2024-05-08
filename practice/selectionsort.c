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
   for(int i=0; i<n-1; i++){
        int min=i;  //take out the loc of min element assumed (1st element)
        //compare with remaining element after the 1st element to get the min
        for(int j=i+1; j<n; j++){
            if(arr[min]>arr[j])
                min=j;
        }

        //check it min is updated
        if(min != i)
            swap(&arr[i], &arr[min]);
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