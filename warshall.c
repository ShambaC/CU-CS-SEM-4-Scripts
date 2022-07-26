#include<stdio.h>

int main()
{
    int i, j, k, AdjMat[20][20], size;

    printf("Enter the no of vertices : ");
    scanf("%d", &size);

    printf("\nEnter the adjacency matrix : \n");
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            scanf("%d", &AdjMat[i][j]);
        }
    }

    //Warshall
    for(k = 0; k < size; k++)
    {
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                AdjMat[i][j] = AdjMat[i][j] || (AdjMat[i][k] && AdjMat[k][j]);
            }
        }
    }

    //Output
    printf("\nConnection matrix : \n");
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%d ", AdjMat[i][j]);
        }
        printf("\n");
    }

    return 0;
}