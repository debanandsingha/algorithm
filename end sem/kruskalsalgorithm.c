#include<stdio.h>
#define INF 32000

int N;  //vertices

void createGraph(int G[N][N]);
void printGraph(int G[N][N]);

void kruskalsAlgorithm(int G[N][N]);
int findParent(int, int[]);
int isCycle(int, int, int[]);

void main(){
    printf("Enter no. of nodes: ");
    scanf("%d",&N);

    int G[N][N];
    createGraph(G);

    kruskalsAlgorithm(G);
}

void kruskalsAlgorithm(int G[N][N]){
    int parent[N];
    for(int i=0; i<N; i++)
        parent[i]=0;

    int a,b,x,y,i,j,min;
    int no_edge=0, sum=0;

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            if(G[i][j]==0)
                G[i][j]=INF;
    
    printf("Edge : Weight\n");
    while(no_edge<N-1){
        min=INF;
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(min>G[i][j]){
                    min=G[i][j];
                    x=a=i;
                    y=b=j;
                }
            }
        }
        a=findParent(a, parent);
        b=findParent(b, parent);

        if(isCycle(a,b, parent)==1){
            sum+=min;
            printf("%d - %d : %d\n",x,y,G[x][y]);
            no_edge++;
        }
        G[x][y]=G[y][x]=INF;
    }

    printf("Total cost of the graph: %d\n",sum);
}

int findParent(int a, int parent[]){
    while(parent[a])
        a=parent[a];
    return a;
}

int isCycle(int a, int b, int parent[]){
    if(a!=b){
        parent[b]=a;
        return 1;
    }
    return 0;
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