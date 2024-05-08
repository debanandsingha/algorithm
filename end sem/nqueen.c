#include<stdio.h>
#include<stdlib.h>

int x[8]={0};
int count=0;

int nqueen(int, int);
int place(int, int);

void main(){
    nqueen(0, 8);
    printf("Total valid solutions: %d",count);
}

int nqueen(int k, int n){
        if (k == n) {
        // printf("[");
        // for(int j = 0; j < n; j++) {
        //     printf("%d ", x[j] + 1);
        // }
        // printf("] ");
        count++;
        //printf("%d \n", count);
        return;
    }
    for(int i=1; i<=n; i++){
        if(place(k, i)){
            x[k]=i;
            if(k==n){
                printf("[ ");
                for(int j=1; j<=n; j++){
                    printf("%d ",x[j]);
                }
                printf("]");
                printf("\n");
                // count++;
                // printf("Current count: %d",count);
            }else{
                nqueen(k+1, n);
            }
        }
    }
}

int place(int k, int i){
    for(int j=1; j<k; j++){
        if(x[j]==i || abs(x[j]-i) == abs(j-k))
            return 0;
    }
    return 1;
}