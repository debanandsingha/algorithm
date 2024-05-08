#include<stdio.h>
#define INF 36000

void createGraph(int n, int G[n][n]);
void printGraph(int n, int G[n][n]);

void main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int G[n][n];
    createGraph(n, G);
    printGraph(n, G);

    int selected[n];
    for(int i=0; i<n; i++)
        selected[i] = 0;

    int no_edge = 0, i, j, sum=0, x,y;

    selected[0] = 1;
    printf("Edge : Weight\n");
    while(no_edge < n-1){
        int min=INF;
        for(i=0; i<n; i++){
            if(selected[i]==1){
                for(j=0; j<n; j++){
                    if(selected[j]==0 && G[i][j] !=0){
                        if(min > G[i][j]){
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = 1;
    sum+=min;
    no_edge++;
    }
    printf("Minimum cost = %d\n", sum);
}

void createGraph(int n, int G[n][n]){
    //initialing the matrix with 0
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            G[i][j] = 0;
    printf("Enter the weight of the edges: \n");
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            printf("%d <-> %d:  ", i, j);
            scanf("%d", &G[i][j]);
            G[j][i] = G[i][j];
        }
    }
}

void printGraph(int n, int G[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}