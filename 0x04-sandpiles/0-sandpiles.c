#include "sandpiles.h"
/**
 *sandpiles_sum - adds two sandpiles
 *@grid1 : The first grid
 *@grid2 : The second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sandpiles_adding(grid1, grid2);
	while (stability(grid1) != 0)
	{
		printf("=\n");
		printing_grid(grid1);
		topple(grid1);
	}
}
/**
 *sandpiles_adding - Adds the second sandpile in the first sandpile
 *@grid1: The first grid
 *@grid2: The second grid
 */
void sandpiles_adding(int grid1[3][3], int grid2[3][3])
{
	int height, width, x, y;

	for (y = 0, height = 3; y < height; y++)
	{
		for (x = 0, width = 3; x < width; x++)
		{
			grid1[x][y] += grid2[x][y];
		}
	}
}
/**
 *printing_grid - For printing
 *@grid: The grid to be toppled
 */
void printing_grid(int grid[3][3])
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
 *stability - checks the stability of a function
 *@grid1: The grid to be checked
 *Return: 0 if stable, otherwise 1
 */
int stability(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (1);
		}
	}
	return (0);
}
/**
 *topple - Topples a sandpile
 *@grid1: Grid to be toppled
 *
 */
void topple(int grid1[3][3])
{
	int x, y, num;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			num = grid1[y][x];
			if (num >=  4)
			{
				grid1[y][x] =  num - 4;
				if (y - 1 >= 0)
					grid1[y - 1][x] += 1;
				if (y + 1 < 3)
					grid1[y + 1][x] += 1;
				if (x + 1 < 3)
					grid1[y][x + 1] += 1;
				if (x - 1 >= 0)
					grid1[y][x - 1] += 1;
			}
		}
	}
}
