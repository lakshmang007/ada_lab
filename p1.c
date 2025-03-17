#include <stdio.h>

#define max 25
#define INF 999

int parent[max];

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int union_sets(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int n, i, j, a, b, u, v, ne = 1, mincost = 0;
    int adj[max][max];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0)
                adj[i][j] = INF;
        }
    }
    for (i = 1; i <= n; i++)
        parent[i] = 0;
    while (ne < n)
    {
        int min = INF;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (adj[i][j] < min)
                {
                    min = adj[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (union_sets(u, v))
        {
            printf("%d edge (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        adj[a][b] = adj[b][a] = INF;
    }
    printf("Minimum cost = %d\n", mincost);
    return 0;
}