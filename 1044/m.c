#include<stdio.h>

void main() {
    int ans, lb=1, ub=100, mid, key, flag, count = 0;
    //while(1) {
        printf("Guess a number!\n");
    //    printf("Did you guess a number?(1/0): ");
    //    scanf("%d", &ans);
    //    if(ans == 0) break;
    //}
    while(lb <= ub) {
        mid = (lb + ub)/2;
        count++;
        printf("%d, (1. Too low; 2. Too High; 3. Correct): ", mid);
        scanf("%d", &flag);
        if(flag == 1) lb = mid+1;
        else if(flag == 2) ub = mid -1 ;
        else {printf("Congratulations!, number found in %d steps", count); break;};
    }
}