#include "main.h"

/**
 * encode_1337 - Encodes a string into 1337.
 * @str: The string to encode.
 *
 * Return: void
 */
void encode_1337(char *str)
{
	char *ch = str;
	char *leet = "aAeEoOtTlL";
	char *replacements[] = {"4", "3", "0", "7", "1"};
	int i, j;

	while (*ch)
	{
		i = 0;
		while (leet[i])
		{
			if (*ch == leet[i])
			{
				for (j = 0; j < 5; j++)
				{
					if (*ch == leet[j])
					{
						*ch = *replacements[j];
						break;
					}
				}
			}
			i++;
		}
		ch++;
	}
}

