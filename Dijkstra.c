#include<stdio.h>

void Dijkstra(int node, int cost[20][20], int final[20]);

int size;

int main()
{
    int i, j, v, cost[20][20], final[20];

    printf("Enter the number of vertices : ");
    scanf("%d", &size);

    printf("\nEnter the cost matrix : \n");
    for (i = 1; i <= size; i++)
    {
        for(j = 1; j <= size; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nEnter the starting vertex : ");
    scanf("%d", &v);

    Dijkstra(v, cost, final);

    //output
    for(i = 1; i <= size; i++)
    {
        if(i != v)
        {
            printf("\n%d -> %d = %d", v, i, final[i]);
        }
    }

    return 0;
}

void Dijkstra(int node, int cost[20][20], int final[20])
{
    int i, j, visit[20], count = 2, min, next_node;

    //init
    for(i = 1; i <= size; i++)
    {
        visit[i] = 0;
        final[i] = cost[node][i];
    }

    visit[node] = 1;

    while(count <= size)
    {
        min = 999;
        for(i = 1; i <= size; i++)
        {
            if(final[i] < min && !visit[i])
            {
                min = final[i];
                next_node = i;
            }
        }

        visit[next_node] = 1;

        for(i = 1; i <= size; i++)
        {
            if(final[next_node] + cost[next_node][i] < final[i] && !visit[i])
            {
                final[i] = final[next_node] + cost[next_node][i];
            }
        }

        count++;
    }
}