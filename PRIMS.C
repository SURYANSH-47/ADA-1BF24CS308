#include <stdio.h>
float cost[10][10], et[10][10], vt[10],  vis[10], n, sum = 0, e = 0;int k, u, v;
void prims()
{
    int x = 1;
    int min = 999;
    vt[x] = 1;
    vis[x] = 1;
    for (int i = 1; i < n; i++)
    {
        int j = x;
        min = 999;
        while (j > 0)
        {
            k = vt[j];
            for (int m = 2; m <= n; m++)
            {
                if (cost[k][m] < min && vis[m] == 0)
                {
                    min = cost[k][m];
                    u = k;
                    v = m;
                }
            }
            j--;
        }
        vt[++x] = v;
        et[i][1] = u;
        et[i][2] = v;
        e++;
        vis[v] = 1;
        sum = sum + cost[u][v];
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%f", &n);
    printf("Enter the matrix: ");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%f", &cost[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }
    prims();
    printf("The minimum spanning tree is: \n");
    for(int i=1;i<n;i++){
        printf("%f->%f\n",et[i][1],et[i][2]);
    }
    printf("\nThe total cost is: %f",sum);
    return 0;
}
