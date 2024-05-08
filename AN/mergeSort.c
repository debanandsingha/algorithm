#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void mergeSort(int [], int, int);
void merge(int [], int, int, int);

void main(){
        int arr[10], n;
        printf("Enter size of array: ");
        scanf("%d",&n);

        readArray(arr, n);
        printf("Before Sorting: ");
        printArray(arr, n);

	mergeSort(arr, 0, n-1);

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

void mergeSort(int arr[], int lb, int ub){
	int mid;
	if(lb<ub){
		mid=(lb+ub)/2;
		mergeSort(arr, lb, mid);
		mergeSort(arr, mid+1, ub);

		merge(arr, lb, mid, ub);
	}
}


void merge(int arr[], int lb, int mid, int ub){
	int i, j, k, b[10];
	i=lb;
	j=mid+1;
	k=lb;

	while(i<=mid && j<=ub){
		if(arr[i]<=arr[j]){
			b[k] = arr[i];
			i++;
		}else{
			b[k]=arr[j];
			j++;
		}
		k++;
	}

	if(j>ub){
		while(i<=mid){
			b[k]=arr[i];
			k++;
			i++;
		}
	}

	if(i>mid){
		while(j<=ub){
			b[k]=arr[j];
			k++;
			j++;
		}
	}

	for(i=lb; i<ub; i++){
		arr[i]=b[i];
	}
}
