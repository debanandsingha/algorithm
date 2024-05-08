#include<stdio.h>

void readArray(int [], int);
void printArray(int [], int);
void merge2list(int [], int [], int [], int, int);
void swap(int *, int *);

void main(){
        int A[10], B[10], n1, n2, C[20];

        printf("Enter size of array A: ");
        scanf("%d",&n1);
        readArray(A, n1);

        printf("Enter size of arr B: ");
        scanf("%d",&n2);
        readArray(B, n2);

        printf("Array A: ");
        printArray(A, n1);
        printf("Array B: ");
        printArray(B, n2);

	merge2list(A, B, C, n1, n2);
	printf("Merged Array C:");
	printArray(C, n1+n2);


}

void readArray(int arr[], int size){
        printf("Enter %d elements: ",size);
        for(int i=0; i<size; i++)
                scanf("%d",&arr[i]);
}
void printArray(int arr[], int size){
        for(int i=0; i<size; i++)
                printf("%d\t", arr[i]);
        printf("\n");
}

void merge2list(int A[], int B[], int C[], int n1, int n2){
        int c, i, j, k, l, m, n;
	c=n1+n2;

	i=0;
	j=n1-1;

	k=0;
	l=n2-1;

	m=0;
	n=c-1;

	while(i<=j && k<=l){
		C[m++]  = (A[i] <= B[k]) ? A[i++] : B[k++];
	}

	while(k<=l){
		C[m]=B[k];
		m++; k++;
	}

	while(i<=j){
		C[m]=A[i];
		m++; i++;
	}
}

void swap(int *a, int *b){
	int temp =*a;
	*a=*b;
	*b=temp;
}
