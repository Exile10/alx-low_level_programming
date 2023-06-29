#include <stdlib.h>

/**
 * infinite_add - Adds two numbers.
 * @n1: The first number as a string.
 * @n2: The second number as a string.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer.
 *
 * Return: A pointer to the result (r) or 0 if the result cannot be stored in r.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, carry = 0, sum = 0;
	int i, j;

	/* Calculate lengths of n1 and n2 */
	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	/* Check if result can be stored in r */
	if (len1 >= size_r || len2 >= size_r)
		return (0);

	i = len1 - 1;
	j = len2 - 1;
	r[size_r - 1] = '\0';

	/* Perform addition digit by digit */
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

		sum += carry;
		carry = sum / 10;

		r[size_r - 2] = (sum % 10) + '0';

		sum = 0;
		i--;
		j--;
		size_r--;
	}

	if (carry != 0)
	{
		if (size_r == 1)
			return (0);
		r[size_r - 2] = carry + '0';
	}
	return (r + size_r - 1);
}

