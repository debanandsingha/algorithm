#include<stdio.h>

void TOH(int, char, char, char);

int count=0;

void main(){
    int n;
    printf("Enter Number of disks: ");
    scanf("%d",&n);
    TOH(n, 'A', 'C', 'B');
    printf("Total no of steps: %d",count);
}

void TOH(int n, char from, char to, char aux){
    count++;
    if(n == 1){
        printf("Move a disk from %c to %c.\n", from,to);
        return;
    }
    TOH(n-1,from,aux,to);
    printf("Move a disk from %c to %c.\n", from,to);
    TOH(n-1,aux,to,from);

}
