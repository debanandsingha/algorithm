#include<stdio.h>
#include<stdlib.h>

int x[8] = {0};
int count = 0;

int place(int k, int i);
void nqueens(int k, int n);

void main() {
    nqueens(0, 8);
    printf("Total number of solutions: %d", count);
}

void nqueens(int k, int n) {
    if (k == n) {
        printf("[");
        for(int j = 0; j < n; j++) {
            printf("%d ", x[j] + 1);
        }
        printf("] ");
        printf("\n");
        count++;
        return;
    }
   for(int i = 0; i < n; i++) {
        if(place(k, i)) {
            x[k] = i;
            nqueens(k + 1, n);
        }
    }
}

int place(int k , int i) {
    for(int j = 0; j < k; j++) {
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}