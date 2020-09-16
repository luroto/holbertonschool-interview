#include "palindrome.h"
/**
 *is_palindrome - Checks if a number is an unsigned int
 *@n: Integer to be checked
 *Return: If the integer is a palindrome, 1, otherwise 0
 */
int is_palindrome(unsigned long n)
{
	unsigned int temp, rev, last_digit;

	temp = n;
	rev = 0;
	last_digit = 0;
	while (temp > 0)
	{
		last_digit = temp % 10;
		rev = rev * 10 + last_digit;
		temp = temp / 10;
	}
	if (rev == n)
		return (1);
	return (0);
}
