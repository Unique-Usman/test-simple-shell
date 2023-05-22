#include "main.h"

/**
 * _strcspn - gets length of a prefix substring
 * @str: param1
 * @reject: param2
 * Return: number of bytes in the initial segment
 *  of str which are not in the string - reject
 */

size_t _strcspn(const char *str, const char *reject)
{
	const char *str2;
	const char *str1 = str;
	size_t len = 0;

	while (*str1)
	{
		str2 = reject;
		while (*str2)
		{
			if (*str1 == *str2)
			{
				return (len);
			}
			str2++;
		}
		str1++;
		len++;
	}

	return (len);
}
