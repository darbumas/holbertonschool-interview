#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned number is a
 * palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, original = n;

	while (original != 0)
	{
		rev *= 10;
		rev = rev + original % 10;
		original /= 10;
	}
	return (n == rev);
}
