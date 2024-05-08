//Applicable to both directed and undirected graph
#include<stdio.h>

void main(){
    int n;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);

    int G[n][n];
    //Initialize Graph with 0
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            G[i][j]=0;

    //Adjacency Matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //condition for no self loop
            if(i!=j){
                printf("Enter weight between edge %d - %d: ", i, j);
                scanf("%d",&G[i][j]);
            }
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