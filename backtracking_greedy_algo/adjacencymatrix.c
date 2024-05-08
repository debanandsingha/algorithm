#include <stdio.h>

void printGraph(int n, int graph[n][n]);

void main(){
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    // printf("Enter the number of edges: ");
    // scanf("%d", &e);

    int graph[n][n];

    //initialing the matrix with 0
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            graph[i][j] = 0;

//    for(int i=0; i<e; i++){
//     int u, v, w;
//     printf("Edge%d => Enter (u, v, w): ",i+1);
//     scanf("%d %d %d",&u,&v,&w);
//     graph[u][v]=w;
//     graph[v][u]=w;
//    }

    // printf("Enter the weight of the edges: \n");
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         if(i!=j){
    //             printf("%d -> %d:  ", i, j);
    //             scanf("%d", &graph[i][j]);
    //         }
    //     }
    // }
    printf("Enter the weight of the edges: \n");
for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
        printf("%d <-> %d:  ", i, j);
        scanf("%d", &graph[i][j]);
        graph[j][i] = graph[i][j];
    }
}
    
    printGraph(n, graph);
}

void printGraph(int n, int graph[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}