#include <stdlib.h>
#include "main.h"


/**
 * _strcat - concatenates two string
 * @s1: string 1
 * @s2: string 2
 * Return: concatenated strings
 */
char *_strcat(char *s1, char *s2)
{

	int i = 0;
	int ii = 0;
	char *ptr;
	int c = 0;
	int cc = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (*(s1 + i))
		i++;

	while (*(s2 + ii))
		ii++;

	ptr = malloc(sizeof(char) * (i + ii + 1));

	if (ptr == NULL)
		return (NULL);

	while (c < i)
	{
		*(ptr + c) = *(s1 + c);
		c++;
	}

	while (cc < ii)
	{
		*(ptr + c) = *(s2 + cc);
		cc++;
		c++;
	}

	return (ptr);
}
