//heapsort(A, n)
//buildmaxheap(A, n)
//heapify(A, i, n)

#include<stdio.h>

void hs(int [], int);
void buildmaxh(int [], int);
void heapify(int [], int, int);

void swap(int *, int *);
void readArray(int [], int);
void printArray(int [], int);
void main(){
    int arr[10], n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    readArray(arr, n);
    printArray(arr, n);

    hs(arr, n);
    printArray(arr, n);
}

void hs(int arr[], int n){
    buildmaxh(arr, n);
    //************n-1**************in c last node is n-1
    //decrementing array
    for(int i=n-1; i>0; i--){
        swap(&arr[0],&arr[i]);  //swap root with last node
        heapify(arr, 0, i); //heapify root element where 1 element is less (already sorted)
    }
}

void buildmaxh(int arr[], int n){
    //decrementing loop
    for(int i=n/2; i>=0; i--){
        heapify(arr, i, n);
    }
}

void heapify(int arr[], int i, int n){
    int l=(2*i)+1;  //left child location
    int r=l+1; //(2*i)+2    //right child location
    int max;    //store max element location

    //if left child exists and its element is greater 
    //then parent then it is max
    if(l<n && arr[l]>arr[i])
        max=l;
    else
        max=i;
    
    if(r<n && arr[r]>arr[max])
        max=r;

    //check if parent is not the max element
    if(max != i){
        swap(&arr[max], &arr[i]);
        heapify(arr, max, n);
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