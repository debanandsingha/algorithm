//quicksort(A, lb, ub)
//partition(A, lb, ub)

#include<stdio.h>

void qs(int [], int, int);
int partition(int [], int, int);
void swap(int *, int *);
void readArray(int [], int);
void printArray(int [], int);
void main(){
    int arr[10], n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    readArray(arr, n);
    printArray(arr, n);

    qs(arr, 0, n-1);
    printArray(arr, n);
}

void qs(int arr[], int lb, int ub){
    if(lb<ub){
        int p=partition(arr, lb, ub);   //pivot loc
        qs(arr, lb, p-1);       //less than pivot(1st Partition)
        qs(arr, p+1, ub);   //greater than pivot(2nd Partition)
    }
}

// last element as pivot
// int partition(int arr[], int lb, int ub){
//     int i=lb-1;
//     int j=lb;
//     int x=arr[ub];  //pivot

//     while(j<ub){
//         if(arr[j]<=x){
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//         j++;
//     }

//     swap(&arr[i+1], &arr[j]);   //as soon as j==ub loop stops so j=ub
//     return i+1;
// }

//first element as pivot
int partition(int arr[], int lb, int ub){
    int i=lb;
    int j=ub;
    int x=arr[lb];

    //till start ptr is less than end ptr
    while(i<j){
        //increment i if it is less than or equal to pivot
        //stop it when element is greater than pivot
        //Finds the element greater than pivot
        while(arr[i]<=x){
            i++;
        }

        //decrement j if it is greater than pivot
        //stop it when element is less than pivot
        //Finds the element which is less than pivot
        while(arr[j]>x){
            j--;
        }
        //swap only if i and j did not crossed each other i.e. i<j
        if(i<j)
            swap(&arr[i], &arr[j]);
    }
    //as i crossed j swap pivot with j as j points to the element less than pivot
    swap(&arr[lb], &arr[j]);    //swap pivot to its appropriate position
    return j;
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