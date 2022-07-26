#include<stdio.h>

int min(int, int);

int main()
{
    int i, j, k, Cost[20][20], size;

    printf("Enter the number of vertices : ");
    scanf("%d", &size);

    printf("\nEnter the cost matrix : \n");
    for (i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            scanf("%d", &Cost[i][j]);
            if(Cost[i][j] == 0)
                Cost[i][j] = 999;
        }
    }

    //Floyd
    for(k = 0; k < size; k++)
    {
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                Cost[i][j] = min(Cost[i][j], Cost[i][k] + Cost[k][j]);
            }
        }
    }

    //Output
    printf("\nShortest connection matrix : \n");
    for (i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%d ", Cost[i][j]);
        }
        printf("\n");
    }

    return 0;   
}

int min(int a, int b)
{
    return a<b?a:b;
}