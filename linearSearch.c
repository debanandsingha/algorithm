//Lab 1
#include<stdio.h>

void linearSearch(int [], int);
void arrayReadWrite(int [], int);

void main(){

    int arr[10], size;
    printf("Enter size of Array: ");
    scanf("%d",&size);

    arrayReadWrite(arr,size);
    linearSearch(arr, size);

}

void arrayReadWrite(int arr[], int size){
    int i;
    printf("Enter %d elements: ",size);
    for(i=0; i<size; i++)
        scanf("%d",&arr[i]);
    printf("Array Elements: ");
    for(i=0; i<size; i++)
        printf("%d\t",arr[i]);
    
    printf("\n");
}

void linearSearch(int arr[], int size){
    int key, flag=0;
    printf("Enter Element to search: ");
    scanf("%d",&key);

    for(int i=0; i<size; i++){
        if(key==arr[i]){
            flag=1;
            break;
        }
        // printf("%d",i);
    }
    if(flag == 1){
        printf("Element Found!");
    }else{
        printf("Element Not Found!!");
    }
}


