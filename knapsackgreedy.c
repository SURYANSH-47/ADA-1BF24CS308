#include <stdio.h>

float vis[10];

void knapsack(int m, int n, int w[], int p[])
{
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    float ratio[n];
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (float)p[i] / w[i];
    }

    int count = 0;
    while (m > 0 && count < n)
    { 
        float max = -1;
        int index = -1;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0 && ratio[i] > max)
            {
                max = ratio[i];
                index = i;
            }
        }

        if (index == -1)
            break; 

        if (w[index] > m)
        {
            vis[index] = (float)m / w[index];
            m = 0; 
        }
        else
        {
            vis[index] = 1;
            m = m - w[index];
        }
        count++;
    }
}

int main()
{
    int m, n;
    printf("Enter the capacity of the bag: ");
    scanf("%d", &m);
    printf("Enter number of objects: ");
    scanf("%d", &n);

    int w[n], p[n];
    printf("Enter the weights and profits for the %d objects:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &p[i]);
    }

    knapsack(m, n, w, p);

    float totalProfit = 0;
    printf("\nResulting Vector (vis): ");
    for (int i = 0; i < n; i++)
    {
        totalProfit += (p[i] * vis[i]);
        printf("%.2f ", vis[i]);
    }
    printf("\nThe total profit is: %.2f\n", totalProfit);

    return 0;
}