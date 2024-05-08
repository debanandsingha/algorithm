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
int selected[V]={0};

void readgraph(){
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int no_edge=0;
	int i,j,sum=0;
	int x;
	int y;
	selected[0] = 1;

	printf("Graph::\n");
	readgraph();

	printf("Edge : Weight\n");

	while (no_edge < V - 1) {

		int min = INF;
		x = 0;
		y = 0;
		for (i = 0; i < V; i++) {
			if (selected[i]==1) {
				for (j = 0; j < V; j++) {
					if (selected[j]==0 && G[i][j]!=0) {
						if (min > G[i][j]) {
							min = G[i][j];
							x = i;//0(a)
							y = j;//1(b)
						}
					}
				}
			}
		}
		sum+=min;

		printf("%d - %d : %d\n", x, y, G[x][y]);// 0(a) - 1(b):3

		selected[y] = 1;//1(b)

		no_edge++;

	}
printf("Total cost of the graph %d\n",sum);

return 0;

}
