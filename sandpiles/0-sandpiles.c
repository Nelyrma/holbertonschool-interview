#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
void print_grid(int grid[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * is_stable - checks if the grid is stable
 * @grid: the grid to check
 * Return: 1 if stable, 0 if not
 */
int is_stable(int grid[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return (0);
        }
    }
    return (1);
}

/**
 * topple - topples the grid
 * @grid: the grid to topple
 * Return: void
 */
void topple(int grid[3][3])
{
    int i, j;
    int topple_grid[3][3] = {{0}};

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] >= 4)
            {
                grid[i][j] -= 4;
                if (i - 1 >= 0)
                    topple_grid[i - 1][j]++;
                if (i + 1 < 3)
                    topple_grid[i + 1][j]++;
                if (j - 1 >= 0)
                    topple_grid[i][j - 1]++;
                if (j + 1 < 3)
                    topple_grid[i][j + 1]++;
            }
        }
    }

    for (i = 0; i < 3; i++)  /** Nouvelle itération pour éviter la redéfinition de i */
    {
        for (j = 0; j < 3; j++)
        {
            grid[i][j] += topple_grid[i][j];
        }
    }
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: the first grid
 * @grid2: the second grid
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int new_grid[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            new_grid[i][j] = grid1[i][j] + grid2[i][j];
        }
    }

    while (is_stable(new_grid) == 0)
    {
        printf("=\n");
        print_grid(new_grid);
        topple(new_grid);
    }

    for (i = 0; i < 3; i++)  /** Nouvelle itération pour éviter la redéfinition de i */
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] = new_grid[i][j];
        }
    }
}