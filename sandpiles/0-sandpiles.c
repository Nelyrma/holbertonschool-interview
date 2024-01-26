#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
void print_grid(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}


void topple(int grid[3][3])
{
    int topple_grid[3][3] = {{0}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] >= 4)
            {
                grid[i][j] -= 4;
                if (i - 1 >= 0) topple_grid[i - 1][j]++;
                if (i + 1 < 3) topple_grid[i + 1][j]++;
                if (j - 1 >= 0) topple_grid[i][j - 1]++;
                if (j + 1 < 3) topple_grid[i][j + 1]++;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] += topple_grid[i][j];
        }
    }
}


void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    printf("=\n");
    print_grid(grid1);

    while (1) {
        int unstable = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid1[i][j] > 3) {
                    unstable = 1;
                    break;
                }
            }
            if (unstable) break;
        }

        if (unstable) {
            topple(grid1);
            printf("=\n");
            print_grid(grid1);
        } else {
            break;
        }
    }
}
