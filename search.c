/*
    Write a C program to implement linear search. The program should prompt the user to enter 
    the key value as many times as desired to find it. If the key value is found, the program should 
        print "Yes, the number is found at position i." 
    Ensure that your program can handle any invalid inputs.
    
    Optimize the program by creating functions for linear search and binary search. 
    Prompt the user to choose their preferred search method for finding a specific value. 
    
    The Binary Search algorithm functions effectively only when the numbers are in sorted order. If your input is not sorted, how would you manage and apply the Binary Search algorithm to 
    it?
*/

#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void linearSearch(int [], int);
void binarySearch(int [], int);
void bubbleSort(int [], int);
void swap(int *, int *);

void main(){

    int arr[10], size, select_algo;
    char choice;
    printf("Enter size of array: ");
    scanf("%d",&size);
    
    readArray(arr, size);
    printArray(arr,size);

    select_again:
    printf("\n\nSelect SEARCHING ALGORITHM: ( [1]: Linear Search\t[2]: Binary Search ): ");
    scanf("%d",&select_algo);

    switch (select_algo)
    {
    case 1:
        printf("\nLINEAR SEARCH ALGORITHM...\n");

        while(choice != 'n'){
            printArray(arr, size);
            linearSearch(arr, size);
            choose_again:
            printf("\n\nDo you want to search again? (y/n): ");
            scanf("%s",&choice);
            if(choice == 'n')
                printf(">> Exiting...");
            else if(choice != 'y'){
                printf(">> Invalid, enter again!");
                goto choose_again;
            }
        }
        break;
    case 2:
        printf("\nBINARY SEARCH ALGORITHM...\n");

        while(choice != 'n'){
            bubbleSort(arr, size);
            printArray(arr,size);
            binarySearch(arr, size);

            printf("\n\nDo you want to search again? (y/n): ");
            scanf("%s",&choice);
            if(choice == 'n')
                printf(">> Exiting...");
            else if(choice != 'y'){
                printf(">> Invalid, enter again!");
                goto choose_again;
            }
        }
        break;
    
    default:
        if(select_algo != 1 || select_algo !=2){
            printf(">> Invalid, enter again!");
            goto select_again;
        }
        break;
    }
}


void readArray(int arr[], int size){
    printf("Enter %d elements: ",size);
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);
}

void printArray(int arr[], int size){
    printf(">> Array Elements:\t");
    for(int i=0; i<size; i++)
        printf("%d\t",arr[i]);
    printf("\n");
}

void linearSearch(int arr[], int size){
    int key, i, flag=0;
    printf("Enter the key value to search: ");
    scanf("%d",&key);

    for(i=0; i<size; i++){
        if(key==arr[i]){
            flag=1;
            break;
        }
    }

    if(flag == 1){
        printf(">> Yes, the number %d is found at position %d.", key, i+1);
    }else{
        printf(">> No, the number %d is not found in the array.", key);
    }
}

void binarySearch(int arr[], int size){
    int key, lowerBound=0, upperBound=size, mid;

    printf("Enter the key value to search: ");
    scanf("%d",&key);

    while(lowerBound <= upperBound){
        mid = (lowerBound+upperBound)/2;
        if(key == arr[mid]){
            printf(">> Yes, the number %d is found at position %d.", key, mid+1);
            return;
        }
        if(key < arr[mid]){
            upperBound = mid-1;
        }else{
            lowerBound = mid+1;
        }
    }
    printf(">> No, the number %d is not found in the array.", key);
}

void bubbleSort(int arr[], int size){
    int i, j;
    for(i=0; i<size; i++){
        for(j=i+1; j<size; j++){
            if(arr[i]>arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
    
}

void swap(int *a,int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}