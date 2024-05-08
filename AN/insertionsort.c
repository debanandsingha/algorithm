#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void insertionSort(int [], int);

void main(){
        int arr[10], size;
        printf("Enter size of the array: ");
        scanf("%d",&size);

        readArray(arr, size);
        printf("Before Sorting: ");
        printArray(arr,size);

        insertionSort(arr, size);

        printf("After sorting: ");
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


void insertionSort(int arr[], int size){
	int i,j, item;

	for(i=1; i<size; i++){
		item = arr[i];
		j=i-1;
		while(item<arr[j] && j>=0){
			if(item < arr[j])
				arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=item;
	}
}
