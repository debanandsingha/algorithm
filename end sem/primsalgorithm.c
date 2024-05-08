#include<stdio.h>
#define INF 32000

int N;  //vertices

void createGraph(int G[N][N]);
void printGraph(int G[N][N]);
void primsAlgorithm(int G[N][N]);

void main(){
    printf("Enter no. of nodes: ");
    scanf("%d",&N);

    int G[N][N];
    createGraph(G);

    primsAlgorithm(G);
}

void primsAlgorithm(int G[N][N]){
    int selected[N];
    for(int i=0; i<N; i++)
        selected[i]=0;

    int no_edge=0;
    int i, j, sum=0;
    int x, y;
    selected[0]=1;

    printf("Edge : Weight\n");
    while(no_edge<N-1){
        int min=INF;
        x=0;
        y=0;

        for(i=0; i<N; i++){
            if(selected[i]==1){
                for(j=0; j<N; j++){
                    if(selected[j]==0 & G[i][j]!=0){
                        if(min>G[i][j]){
                            min=G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        sum+=min;
        printf("%d - %d : %d\n", x,y,G[x][y]);
        selected[y]=1;
        no_edge++;
    }
    printf("Total cost of the graph %d\n",sum);
}

//Adjacency Matrix for undirected weighted graph
void createGraph(int G[N][N]){
    printf("\nCreating Graph...\n");

    //Initialize matrix with 0
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            G[i][j]=0;
    
    //Graph Representation
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            printf("Enter weight of edge %d - %d: ", i, j);
            scanf("%d",&G[i][j]);
            G[j][i]=G[i][j];
        }
    }

    printf("Adjacency Matrix:\n");
    printGraph(G);

    printf("Graph Created!\n\n");
}

void printGraph(int G[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}