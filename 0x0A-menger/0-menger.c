#include "menger.h"
#include <unistd.h>
#include <math.h>

/**
 * _putchar - print the character c to stdout
 * @c: The character to print
 *
 * Return: 1 if success, -1 if error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_menger - Determines whether to print a '#' or a space character for a
 * given row and column
 * @level: The level of the Menger sponge
 * @row: The row of the current position
 * @col: the column of the current position
 */
void print_menger(int level, int row, int col)
{
	/* Iterate through the levels of the Menger sponge */
	while (level > 0)
	{
		if ((row % 3 == 1) && (col % 3 == 1))
		{
			_putchar(' ');
			return;
		}
		/* Move to the next level */
		row /= 3;
		col /= 3;
		level--;
	}
	/* If not in the center of a 3x3 block, print a '#' */
	_putchar('#');
}

/**
 * menger - Function that draws a 2D Menger sponge
 * @level: The level of the Menger sponge to draw
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	/* Calculate the size of the Menger sponge for the given level */
	size = pow(3, level);

	/* Iterate through each row and column of the sponge */
	for (row = 0; row < size; ++row)
	{
		for (col = 0; col < size; ++col)
			print_menger(level, row, col);
		_putchar('\n');
	}
}

