#include <stdio.h>

// Increased size to handle up to 10 objects and 10 capacity safely
int v[11][11];
int profit;
int x[11];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapsack(int n, int m, int w[], int p[])
{
    profit=0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
        
            else if (w[i - 1] > j)
            {
                v[i][j] = v[i - 1][j];
                if(v[i][j]>profit)profit=v[i][j];
            }
            else
            {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i - 1]] + p[i - 1]);
                if (v[i][j] > profit)
                    profit = v[i][j];
            }
        }
    }
    
}

void oselect(int n, int m, int w[])
{
    int i = n;
    int j = m;
    while (i > 0 && j > 0)
    {
        if (v[i][j] != v[i - 1][j])
        {
            x[i - 1] = 1; 
            j = j - w[i - 1];
        }
        else
        {
            x[i - 1] = 0;
        }
        i--;
    }
}

int main()
{
    int m, n;
    printf("Enter the capacity of the bag: ");
    if (scanf("%d", &m) != 1)
        return 1;
    printf("Enter number of objects: ");
    if (scanf("%d", &n) != 1)
        return 1;

    int w[n], p[n];
    printf("Enter the weights and profits for the %d objects:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &p[i]);
    }

    knapsack(n, m, w, p);
    oselect(n, m, w);

    
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1)
        {
            printf("Object %d is selected \n", i + 1);
        }
    }
    printf("The total profit is: %d\n", profit);

    return 0;
}