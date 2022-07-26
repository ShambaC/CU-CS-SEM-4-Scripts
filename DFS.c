#include<stdio.h>

int size, count = 0;

void DFS(int, int mat[20][20], int v[20]);

int main()
{
    int i, j, AdjMat[20][20], visit[20];

    printf("Enter the number of vertices : ");
    scanf("%d", &size);

    //Init
    for(i = 1; i <= size; i++)
    {
        visit[i] = 0;
    }

    printf("\nEnter the adjacency matrix : \n");
    for(i = 1; i <= size; i++)
    {
        for(j = 1; j <= size; j++)
        {
            scanf("%d", &AdjMat[i][j]);
        }
    }

    printf("\nDFS of the graph : \n");

    DFS(1, AdjMat, visit);
    
    return 0;
}

void DFS(int node, int Mat[20][20], int visited[20])
{
    int i, j;

    printf("%d ", node);
    count++;
    if(count != size)
    {
        printf("->");
    }

    visited[node] = 1;

    for(i = 1; i <= size; i++)
    {
        if(Mat[node][i] && !visited[i])
        {
            DFS(i, Mat, visited);
        }
    }
    
}