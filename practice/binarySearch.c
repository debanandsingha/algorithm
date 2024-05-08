#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void sort(int [], int);
void swap(int *, int *);

int binarySearch(int [], int, int, int);    //recursive
int binS(int [], int, int, int);    //iterative

void main(){
    int arr[10], n;
    int key;
    printf("Enter size of array: ");
    scanf("%d",&n);

    readArray(arr, n);
    printArray(arr, n);

    sort(arr, n);
    printArray(arr,n);

    printf("Enter element to search: ");
    scanf("%d",&key);
    // int x=binarySearch(arr, 0, n-1, key);
    int x=binS(arr, 0, n-1, key);

     if(x==-1){
        printf("Element not found");
    }else{
        printf("Element found at position %d", x+1);
    }
}

//Recursive
int binarySearch(int arr[], int lb, int ub, int key){
    int mid;
    if(lb<=ub){
        mid=(lb+ub)/2;
        if(key==arr[mid]){
            return mid;
        }else if(key>arr[mid]){
            return binarySearch(arr, mid+1, ub, key);
        }else{
            return binarySearch(arr, lb, mid-1, key);
        }
    }
    return -1;
}

//Iterative
int binS(int arr[], int lb, int ub, int key){
    int mid;
    while(lb<=ub){
        mid=(lb+ub)/2;
        if(key==arr[mid])
            return mid;
        else if(key>arr[mid])
            lb=mid+1;
        else
            ub=mid-1;
    }
    return -1;
}

void sort(int arr[], int n){
    int flag=1;
    for(int i=0; i<n-1 && flag==1 ; i++){
        // printf("i: %d\n",i);
        flag=0;
        for(int j=0; j<n-i-1; j++){
            // printf("j: %d ", j);
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                flag=1;
            }
            // printf("\n");
        }
        // printf("\n");
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