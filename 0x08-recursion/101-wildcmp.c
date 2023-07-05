#include "main.h"
/**
 * wildcmp - Compare two strings allowing wildcard *
 * @s1: First string
 * @s2: Second string with wildcard *
 *
 * Return: 1 if the strings are considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0') /* If s2 ends with *, return 1 */
			return (1);
		else if (*s1 == '\0') /* If s1 ends but s2 has more characters after *, return 0 */
			return (0);
		else if (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))
			/*
			 * Recursively check if s1 matches the remaining part of s2
			 * or if s1 is skipped and s2 continues with the next character after *
			 */
			return (1);
		else
			return (0);
	}
	else if (*s1 == '\0' || *s2 == '\0')
	{
		/* If either s1 or s2 ends, return 0 (not identical) */
		return (0);
	}
	else if (*s1 != *s2)
	{
		/* If characters at the current positions do not match, return 0 */
		return (0);
	}
	else
	{
		/* Move to the next characters and continue comparing */
		return (wildcmp(s1 + 1, s2 + 1));
	}
}

