#include <stdio.h>

int a[10][10];
int n, m;
int visited[10];

void topologi()
{
    int count = 0;
    while (count < n)
    {
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int k = 0;
                for (int j = 0; j < n; j++)
                {
                    if (a[j][i] == 1)
                    {
                        k= 1;
                        break;
                    }
                }

                if (k == 0)
                {
                    printf("%d ", i);
                    visited[i] = 1;
                    count++;
                    found = 1;

                    for (int l = 0; l < n; l++)
                    {
                        a[i][l] = 0;
                    }
                    i = -1;
                }
            }
        }
        if (!found && count < n)
            break;
    }
}

int main()
{
    int u, v;
    for (int i = 0; i < 10; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < 10; j++)
            a[i][j] = 0;
    }

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        a[u][v] = 1;
    }

    printf("TOPOLOGICAL ORDER IS: ");
    topologi();
    printf("\n");

    return 0;
}