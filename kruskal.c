#include<stdio.h>

int parent[20];

int find(int);
int uni(int a, int b);

int main()
{
    int i, j, cost[20][20], size, ne = 1, final_cost = 0, min, u, v, a, b;

    printf("Enter the number of vertices : ");
    scanf("%d", &size);

    //Init
    for (i = 0; i < size; i++)
    {
        parent[i] = 0;
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

    //Kruskal
    while(ne < size)
    {
        for (i = 0, min = 999; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(uni(u, v))
        {
            printf("\nEdge %d : (%d, %d) : cost = %d", ne++, a, b, min);
            final_cost += min;
        }
        cost[a][b] = cost[b][a] = 999;
        
    }
    printf("\nFinal Cost = %d", final_cost);

    return 0; 
}

int find(int a)
{
    while(parent[a])
    {
        a = parent[a];
    }
    return a;
}

int uni(int a, int b)
{
    if(a != b)
    {
        parent[b] = a;
        return 1;
    }
    return 0;
}

