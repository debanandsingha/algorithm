#include<stdio.h>

#define INF 32000
#define V 6

int G[V][V] = {
        {0, 3, 0, 0, 6, 5},
        {3, 0, 1, 0, 0, 4},
        {0, 1, 0, 6, 0, 4},
        {0, 0, 6, 0, 8, 5},
        {6, 0, 0, 8, 0, 2},
        {5, 4, 4, 5, 2, 0}
        };

int parent[V]={0};

int findParent(int);
int isCycle(int, int);

void main(){
        int a,b,x,y,i,j,min;
        int no_edge=0, sum=0;

        for(i=0; i<V; i++)
                for(j=0; j<V; j++)
                        if(G[i][j]==0)
                                G[i][j]=INF;

        while(no_edge < V-1){
                min=INF;
                for(i=0; i<V; i++){
                        for(j=0; j<V; j++){
                                if(min>G[i][j]){
                                        min=G[i][j];
                                        x=a=i;
                                        y=b=j;
                                }
                        }
                }

                a=findParent(a);
                b=findParent(b);

                if(isCycle(a,b)==1){
                        sum+=min;
                        printf("%d - %d : %d\n",x,y,G[x][y]);
                        no_edge++;
                }

                G[x][y]=G[y][x]=INF;
        }

        printf("Total cost of the graph: %d\n",sum);

}

int findParent(int a){

        while(parent[a])
                a=parent[a];

return a;
}

int isCycle(int a, int b){
        if(a!=b){
                parent[b]=a;
                return 1;
        }
return 0;

}