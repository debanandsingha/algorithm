#include<stdio.h>

void main(){
	int  vertices, i, j;

	printf("Enter no. of vertices: ");
	scanf("%d",&vertices);


	int graph[vertices][vertices];

	for(i=0; i<vertices; i++){
		for(j=0; j<vertices; j++){
			printf("Enter weight of vertex from %d to %d: ",i+1,j+1);
			scanf("%d",&graph[i][j]);
		}
	}

	for(i=0; i<vertices; i++){
		for(j=0; j<vertices; j++){
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}

}
