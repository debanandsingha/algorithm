#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);

int linearSearch(int [], int, int);
void main(){
    int arr[10], n, key;
    printf("Enter size of array: ");
    scanf("%d",&n);

    readArray(arr, n);
    printArray(arr, n);

    printf("Enter element to search: ");
    scanf("%d",&key);
    int x=linearSearch(arr, n, key);

//check condition for element not found
    if(x==-1){
        printf("Element not found");
    }else{
        printf("Element found at position %d", x+1);
    }
}

int linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(key == arr[i]){
            return i;
        }
    }
    return -1;  //dont return 0 coz 0 is a index
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
    printf("]");
}