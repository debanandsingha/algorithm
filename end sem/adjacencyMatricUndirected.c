//Applicable to undirected graph only
#include<stdio.h>

void main(){
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);

    int G[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            G[i][j]=0;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            printf("Enter weight of edge %d <-> %d: ", i, j);
            scanf("%d",&G[i][j]);
            G[j][i]=G[i][j];
        }
    }

    //Print Graph
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}