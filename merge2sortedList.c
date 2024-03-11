#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void bubbleSort(int [], int);
void swap(int *, int *);
void merge2SortedList(int [], int [], int [], int, int);

void main(){
    int A[10], B[10], C[20], n1, n2;
    
    printf("Enter size of the array A: ");
    scanf("%d",&n1);
    readArray(A, n1);

    printf("Enter size of the array B: ");
    scanf("%d",&n2);
    readArray(B, n2);

    printf("Array A: ");
    printArray(A, n1);
    printf("Array B: ");
    printArray(B, n2);
    
    bubbleSort(A, n1);
    bubbleSort(B, n2);
    merge2SortedList(A, B, C, n1, n2);

    printf("Merged Array:\t");
    printArray(C, n1+n2);
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

void bubbleSort(int arr[], int size){
    int i, j, flag=1;
    for(i=0; i<size-1 && flag==1; i++){
        flag=0;
        for(j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                flag=1;
            }
        }
    }
    
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge2SortedList(int A[], int B[], int C[], int n1, int n2){
    int i, j, k, l, m, n, n3;
    
    n3=n1+n2;

    i=0;
    j=n1-1;

    k=0;
    l=n2-1;

    m=0;
    n=n3-1;

    while(i<=j && k<=l){
        // if(A[i] <= B[k]){
        //     C[m]=A[i];
        //     i++;
        // }else{
        //     C[m]=B[k];
        //     k++;
        // }
        C[m++] = (A[i] <= B[k]) ? A[i++] : B[k++];
        // m++;
    }
    
    while(k<=l){
        C[m]=B[k];
        m++;
        k++;
    }

    while(i<=j){
        C[m]=A[i];
        m++;
        i++;
    }
}