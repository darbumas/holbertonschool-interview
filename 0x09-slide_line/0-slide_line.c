#include "slide_line.h"

/**
 * slide_right - slide and merge array in the right direction
 * @line: pointer to an array of integers
 * @size: size of the line array
 */
void slide_right(int *line, size_t size)
{
	size_t i, j, pos = size - 1;

	/* Iterate through the array in reverse */
	for (i = size - 1; i < size; i--)
	{
		/* skip the zeros */
		if (line[i] == 0)
			continue;

		/* find previous non-zero element */
		for (j = i - 1; j < size && line[j] == 0; j--)
			;

		/* check if the current element can be merged with prev non 0 */
		if (j < size && line[i] == line[j])
		{
			/* merge and update the merge position */
			line[pos--] = line[i] * 2;
			i = j;
		}
		else
			/* move the element to the merge position */
			line[pos--] = line[i];
	}
	/* fill the remaining positions with zeros */
	while (pos < size)
		line[pos--] = 0;
}

/**
 * slide_left - slide and merge array in the left direction
 * @line: pointer to an array of integers
 * @size: size of the line array
 */
void slide_left(int *line, size_t size)
{
	size_t i, j, pos = 0;

	/*Iterate through the array */
	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;

		/* find the next non-zero element */
		for (j = i + 1; j < size && line[j] == 0; j++)
			;

	/* check if the current element can be merged with the next non 0 el */
		if (j < size && line[i] == line[j])
		{
			/* merge and update the merge position */
			line[pos++] = line[i] * 2;
			i = j;
		}
		else
			/* move the element to the merge position */
			line[pos++] = line[i];
	}
	/* fill the remaining positions with zeros */
	while (pos < size)
		line[pos++] = 0;
}

/**
 * slide_line - slides and merges an array of integers
 * @line: pointer to an array of integers containing size elements
 * @size: size of the array
 * @direction: direction to slide and merge, SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_RIGHT)
		slide_right(line, size);
	else
		slide_left(line, size);

	return (1);
}
