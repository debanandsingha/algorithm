#include<stdio.h>

void main(){
        int  vertices, edges, i, j, s, d;

        printf("Enter no. of vertices: ");
        scanf("%d",&vertices);

	printf("Enter no. of edges: ");
	scanf("%d",&edges);


        int graph[vertices][vertices];

        for(i=0; i<vertices; i++){
                for(j=0; j<vertices; j++){
                        graph[i][j]=0;
                }
        }


	for(i=0; i<edges; i++){
		printf("Enter edge%d from src to dest: ",i+1);
		scanf("%d%d", &s,&d);
		graph[s][d]= 1;
		graph[d][s]=1;
	}


	for(i=0; i<vertices; i++){
		for(j=0; j<vertices; j++){
			printf("%d\t", graph[i][j]);
		}
		printf("\n");
	}

}
