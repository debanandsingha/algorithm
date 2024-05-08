//mergesort(A, lb, ub)
//m2sl(A, lb, mid, ub)

#include<stdio.h>

void ms(int[], int, int);
void m2sl(int[], int, int, int);

void readArray(int [], int);
void printArray(int [], int);
void main(){
    int arr[10], n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    readArray(arr, n);
    printArray(arr, n);

    ms(arr, 0, n-1);
    printArray(arr, n);
}

void ms(int arr[], int lb, int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        ms(arr, lb, mid);   //left part
        ms(arr, mid+1, ub); //right part
        m2sl(arr, lb, mid, ub);
    }
}

void m2sl(int arr[], int lb, int mid, int ub){
    int i=lb;   //left array initiialization
    int j=mid+1;//right array initialization
    int B[ub+1], k=lb;   //secondary array initialization

    //comapre and insert elements in ascending order into secondary array
    while(i<=mid && j<=ub){
        if(arr[i]>arr[j]){
            B[k]=arr[j];
            j++;
        }
        else{
            B[k]=arr[i];
            i++;
        }
        k++;
    }
    //if left array is empty
    if(i>mid){
        while(j<=ub){
            B[k]=arr[j];
            k++;
            j++;
        }
    }
    //if right array is empty
    if(j>ub){
        while(i<=mid){
            B[k]=arr[i];
            k++;
            i++;
        }
    }

    //copy all elements from secondary array to primary array
    for(i=lb; i<=ub; i++){
        arr[i]=B[i];
    }
    //***************** i=lb
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