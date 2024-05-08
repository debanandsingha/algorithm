#include<stdio.h>

void buildMaxHeapTree(int [], int);
void heapify(int [], int, int);
void swap(int *, int *);
void readArray(int [], int);
void printArray(int [], int);
void insertElement(int arr[], int);
void deleteElement(int arr[], int);

void main(){
        int arr[10], n, x;

        printf("Enter size of array: ");
        scanf("%d",&n);
        readArray(arr,n);

        printf("Entered elements: ");
        printArray(arr,n);
        printf("\n");

	printf("Heap Tree: ");
	buildMaxHeapTree(arr,n);
	printArray(arr,n);

	printf("[1] Delete last node\t[2] Delete 1st node\t[3] Insert element");
	scanf("%d",&x);
	switch(x){
		case 1: //delete last node
			printf("Deleting last Node...");
			n--;
			//printf("Heap Tree: ");
			//printArray(arr,n);
			break;
		case 2: //deleting 1st node
			printf("Deleting 1st Node...");
			deleteElement(arr,n);
			n--;
			//printf("Heap Tree: ");
			//printArray(arr,n);
			break;
		case 3: //insert element
			n++;
			insertElement(arr,n);
			printf("heap Tree: ");
			printArray(arr,n);
			break;
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





void insertElement(int arr[], int n){
	printf("Enter element to insert: ");
	scanf("%d", &arr[n-1]);
	int i=n,j;
	while(i>0){
		if(arr[i]>arr[i/2]){
			swap(&arr[i], &arr[i/2]);
		}
		i/=2;
	}
}

void deleteElement(int arr[], int n){
	arr[0]=arr[n-1];
	heapify(arr,0,n-1);
}









void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
}

void readArray(int arr[], int n){
	printf("Enter %d elements: ",n);
	for(int i=0; i<n; i++)
		scanf("%d",&arr[i]);
}

void printArray(int arr[], int n){
	for(int i=0; i<n; i++)
		printf("%d ",arr[i]);
	printf("\n");
}
