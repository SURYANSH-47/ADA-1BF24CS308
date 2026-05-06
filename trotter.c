#include <stdio.h>

int val[20];
int dir[20];
int n;

void print_permutation()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", val[i]);
    }
    printf("\n");
}

int get_mobile_idx()
{
    int mobile_idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (dir[i] == 0 && i > 0 && val[i] > val[i - 1])
        {
            if (mobile_idx == -1 || val[i] > val[mobile_idx])
            {
                mobile_idx = i;
            }
        }
        else if (dir[i] == 1 && i < n - 1 && val[i] > val[i + 1])
        {
            if (mobile_idx == -1 || val[i] > val[mobile_idx])
            {
                mobile_idx = i;
            }
        }
    }
    return mobile_idx;
}

void swap(int i, int j)
{
    int temp_v = val[i];
    val[i] = val[j];
    val[j] = temp_v;

    int temp_d = dir[i];
    dir[i] = dir[j];
    dir[j] = temp_d;
}

void generate_permutations()
{
    for (int i = 0; i < n; i++)
    {
        val[i] = i + 1;
        dir[i] = 0;
    }

    print_permutation();

    while (1)
    {
        int m = get_mobile_idx();
        if (m == -1)
            break;

        int mobile_val = val[m];

        if (dir[m] == 0)
        {
            swap(m, m - 1);
        }
        else
        {
            swap(m, m + 1);
        }

        for (int i = 0; i < n; i++)
        {
            if (val[i] > mobile_val)
            {
                if (dir[i] == 0)
                    dir[i] = 1;
                else
                    dir[i] = 0;
            }
        }
        print_permutation();
    }
}

int main()
{
    printf("Enter n: ");
    scanf("%d", &n);
    if (n > 0 && n <= 20)
    {
        generate_permutations();
    }
    return 0;
}