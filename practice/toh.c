#include<stdio.h>

void toh(int, char, char, char);
int count=0;

void main(){
    int n;


    printf("Enter number of disks: ");
    scanf("%d",&n);

    toh(n, 'S', 'A', 'D');
    printf("%d", count);
}

void toh(int n, char s, char a, char d){
    count++;
    if(n==1){
        printf("%c -> %c\n", s,d);
        return;
    }else{
        toh(n-1, s,d,a);
        printf("%c -> %c\n", s,d);
        toh(n-1, a, s, d);
    }
}