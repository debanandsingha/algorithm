#include<stdio.h>

void binarySearch(int arr[], int size);
void bubbleSort(int arr[], int size);
void arrayReadWrite(int arr[], int size);

void main(){
    int arr[10], size;
    printf("Enter size of Array: ");
    scanf("%d",&size);

    arrayReadWrite(arr,size);
    bubbleSort(arr, size);
    binarySearch(arr,size);
}

void arrayReadWrite(int arr[], int size){
    int i;
    printf("Enter %d elements: ",size);
    for(i=0; i<size; i++)
        scanf("%d",&arr[i]);
    printf("Array Elements: ");
    for(i=0; i<size; i++)
        printf("%d\t",arr[i]);

    printf("\n");
}

void bubbleSort(int arr[], int size){
    int i, j, temp;;
    for(i=0; i<size; i++){
        for(j=i+1; j<size; j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
}

void binarySearch(int arr[], int size){
    int key, lowerBound=0, upperBound=size, mid;

    printf("Enter Element to search: ");
    scanf("%d",&key);

    while(lowerBound <= upperBound){
        mid = (lowerBound+upperBound)/2;
        if(key == arr[mid]){
            printf("Element Found at index [%d]", mid);
            return;
        }
        if(key < arr[mid]){
            upperBound = mid-1;
        }else{
            lowerBound = mid+1;
        }
    }

    printf("Element Not Found");
}