#include<stdio.h>

int size, count = 0;
int queue[20], front = 0, rear = 0;

void BFS(int, int a[20][20], int v[20]);

int main()
{
    int i, j, AdjMat[20][20], visited[20];

    printf("Enter the size of the graph : ");
    scanf("%d", &size);

    //Init
    for(i = 1; i <= size; i++)
    {
        visited[i] = 0;
    }

    printf("\nEnter the Adjacency matrix : \n");
    for(i = 1; i <= size; i++)
    {
        for(j = 1; j <= size; j++)
        {
            scanf("%d", &AdjMat[i][j]);
        }
    }

    BFS(1, AdjMat, visited);

    return 0;
}

void BFS(int node, int Mat[20][20], int visit[20])
{
    int i;
    visit[node] = 1;
    printf("%d ", node);
    count++;
    if(count != size)
    {
        printf("->");
    }

    for(i = 1; i <= size; i++)
    {
        if(Mat[node][i] && !visit[i])
        {
            queue[++front] = i;
            visit[i] = 1;
        }
    }

    if(count != size)
    {
        BFS(queue[++rear], Mat, visit);
    }

}