#include <stdio.h>
#include <stdlib.h>

/**
 * climb_stairs - calculate the number of ways to climb n stairs
 * @n: number of stairs
 *
 * NOTE: uses Fibonacci sequence to calculate number of ways to climb n stairs
 *
 * Return: number of ways to climb n stairs
 */
int climb_stairs(int n)
{
	int i, first, second, temp;

	if (n <= 2)
		return (n);

	first = 1;
	second = 2;
	i = 3;

	for (; i <= n; i++)
	{
		temp = first + second;
		first = second;
		second = temp;
	}

	return (second);
}

/**
 * main - entry point
 *
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0
 */

int main(int argc, char **argv)
{
	int n;

	if (argc != 2)
	{
		printf("Usage: %s <number of stairs>\n", argv[0]);
		return (1);
	}

	n = atoi(argv[1]);

	printf("Number of distinct ways to climb %d stairs is [%d]\n",
			n, climb_stairs(n));

	return (0);
}
