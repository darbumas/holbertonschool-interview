#include "sandpiles.h"

#define IN_RANGE(x, y) (x >= 0 && x < 3 && y >= 0 && y < 3)

/**
 * print_grid - prints 3x3 matrix with a space
 * @grid: is 3x3 the grid to print
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
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
 * topple - do the toppling operation on a cell w/
 * more than 3 sands by substracting 4 from the cell and
 * redistributing those by 1 to its neighbor cells.
 *
 * @grid: 3x3 grid of integers
 * @i: grid coordinate
 * @j: grid coordinate
 */
void topple(int grid[3][3], int i, int j)
{
	int l_i = 0, l_j = -1;
	int r_i = 0, r_j = 1;
	int u_i = -1, u_j = 0;
	int d_i = 1, d_j = 0;

	grid[i][j] -= 4;

	if (IN_RANGE(l_i + i, l_j + j))
		grid[l_i + i][l_j + j] += 1;
	if (IN_RANGE(r_i + i, r_j + j))
		grid[r_i + i][r_j + j] += 1;
	if (IN_RANGE(u_i + i, u_j + j))
		grid[u_i + i][u_j + j] += 1;
	if (IN_RANGE(d_i + i, d_j + j))
		grid[d_i + i][d_j + j] += 1;
}

/**
 * sandpiles_sum - adds two 3x3 matrices according to sandpiles cellular
 * automata scheme to produce "fractal zeroes".
 *
 * @grid1: first 3x3 matrix, results in the toppled sum of it and grid2
 * @grid2: second matrix to add to grid1
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, balance;
	int pile_limit[3][3];
	/*sum*/
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	do {
		balance = 0;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					pile_limit[i][j] = 1;
					balance = 1;
				}
				else
					pile_limit[i][j] = 0;
			}
		if (balance)
		{
			print_grid(grid1);
			for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
				{
					if (pile_limit[i][j] == 1)
						topple(grid1, i, j);
				}
		}
	} while (balance);
}
