#include<stdio.h>

//Output matrices for final cost and paths
int final[10], path[10][10];

void Djikstra(int n, int v, int cost[10][10]);

int main()
{
	int i, j, size, v, Cost[10][10];
	
	//Taking input for the number of vertice
	printf("Enter the number of vertice : ");
	scanf("%d", &size);
	
	//Inputting the graph
	printf("Enter the cost matrix of the graph : \n");
	for(i=1; i<=size; i++)
	{
		for(j=1; j<=size; j++)
		{
			scanf("%d", &Cost[i][j]);
			if(Cost[i][j] == 0)
				Cost[i][j] = 999;
		}
	}
	
	printf("Enter the starting vertex : ");
	scanf("%d", &v);
	
	//Calling the djikstra method
	Djikstra(size, v, Cost);
	
	//Displaying the shortest path with the cost
	printf("\nThe shortest paths are : \n");
	for(i=1; i<=size; i++)
	{
		printf("v%d -->", v);
		if(i != v)
		{
			for(j=1; j<=size; j++)
			{
				if(path[i][j] != 0)
				{
					if(j == size)
						printf("v%d ", path[i][j]);
					else
						printf("v%d --> ", path[i][j]);
				}
			}
			printf("\n");
			printf("cost = %d\n",final[i]);
			printf("\n");
		}
	}
	
	return 0;
}

void Djikstra(int n, int v, int cost[10][10])
{
	int i, min, next_node, visit[10], count;
	
	//Initialisation
	for(i=1; i<=n; i++)
	{
		visit[i] = 0;
		final[i] = cost[v][i];
		path[1][i] = v;
		path[i][n] = i;
	}
	
	visit[v] = 1;
	count = 2;
	while(count <= n)
	{
		min = 999;
		for(i=1; i<=n; i++)
		{
			//Selecting next node
			if(final[i] < min && !visit[i])
			{
				min = final[i];
				next_node = i;
			}
		}
		
		visit[next_node] = 1;
		count++;
		
		for(i=1; i<=n; i++)
		{
			//checking if selected edge has lower cost
			if(final[next_node] + cost[next_node][i] < final[i] && !visit[i])
			{
				final[i] = final[next_node] + cost[next_node][i];
				int k = 2;
			 	for(int j=2;j<=n;j++)
			 	{
			 		if(path[next_node][j] != 0 && k < n)
			 		{
						path[i][k] = path[next_node][j];
						k++;
					}
				}
			}
		}
	}
}