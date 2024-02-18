#include<stdio.h>

void mergeSort(int [], int, int);
void merge(int [], int, int, int);
void readArray(int [], int);
void printArray(int [], int);

void main(){
    int arr[10], size;

    printf("Enter size of array: ");
    scanf("%d",&size);
    
    readArray(arr,size);
    printf("Before Sorting: ");
    printArray(arr,size);

    mergeSort(arr, 0, size-1);
    printf("After Sorting: ");
    printArray(arr,size);
}

void mergeSort(int arr[], int lb, int ub){
    int mid;
    if(lb<ub){
        mid = (lb+ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
}

void merge(int arr[], int lb, int mid, int ub){
    int i, j, k, arr1[10];
    i=lb;
    j=mid+1;
    k=lb;

    while(i<=mid && j<=ub){
        // if(arr[i]<=arr[j]){
        //     arr1[k]=arr[i];
        //     i++;
        // }else{
        //     arr1[k]=arr[j];
        //     j++;
        // }
        // k++;
        // arr1[k] = (arr[i]<=arr[j]) ? arr[i], i++: arr[j], j++;
        // k++;

        arr1[k++] = (arr[i]<=arr[j]) ? arr[i++] : arr[j++];
    }

    if(i>mid){
        while(j<=ub){
            arr1[k]=arr[j];
            j++;
            k++;
        }
    }else{
        while(i<=mid){
            arr1[k]=arr[i];
            i++;
            k++;
        }
    }

    for(k=lb; k<=ub; k++)
        arr[k]=arr1[k];

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