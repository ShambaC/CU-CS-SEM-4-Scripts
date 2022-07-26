#include<stdio.h>

int main()
{
    int i, j, a, b, ne = 1, size, cost[20][20], final_cost = 0, min, visited[20];

    printf("Enter the number of vertices : ");
    scanf("%d", &size);

    //Init
    for (i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    printf("\nEnter the cost matrix : \n");
    for (i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    
    printf("\nEnter starting vertex : ");
    scanf("%d", &i);
    visited[i] = 1;

    while(ne < size)
    {
        for(i = 0, min = 999; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                if(cost[i][j] <= min)
                {  
                    if(visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if(!visited[a] || !visited[b])
        {
            printf("\nEdge %d : (%d, %d) = %d", ne++, a, b, min);
            final_cost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost = %d", final_cost);

    return 0;
}