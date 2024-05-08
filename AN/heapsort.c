#include<stdio.h>

void heapSort(int [], int);
void buildMaxHeapTree(int [], int);
void heapify(int [], int, int);
void swap(int *, int *);

void main(){
	int arr[10], n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	printf("Enter %d elements: ",n);
	for(int i=0; i<n; i++)
		scanf("%d",&arr[i]);

	printf("Entered elements: ");
	for(int i=0; i<n; i++)
		printf("%d ",arr[i]);
	printf("\n");

	heapSort(arr, n);
	printf("Sorted Array: ");
	for(int i=0; i<n; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void heapSort(int arr[], int n){

	int j=n-1;
	if(n>0){
		buildMaxHeapTree(arr, n);

		swap(&arr[0], &arr[j]);

		j--;
		heapSort(arr, n-1);
	}
}

void buildMaxHeapTree(int arr[], int n){
	for(int i=n/2; i>=0; i--){
		heapify(arr, i, n);
	}
}

void heapify(int arr[], int i, int n){
	int l, r, max;
	l=(2*i)+1;
	r=l+1;

	if(l<n && arr[l]>arr[i])
		max=l;
	else
		max=i;

	if(r<n && arr[r]>arr[max])
		max=r;

	if(max != i){
		swap(&arr[max], &arr[i]);
		heapify(arr, max, n);
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
