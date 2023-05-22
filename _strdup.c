#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * _strdup -  returns a pointer to a newly allocated space in memory
 * @str: string passed
 * Return: string value
 */
char *_strdup(char *str)
{

	char *ptr;
	int i = 0;
	int ii = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + i))
		i++;


	ptr = malloc(sizeof(char) * (i + 1));

	if (ptr == NULL)
		return (NULL);

	i = i + 1;

	while (ii < i)
	{
		ptr[ii] = str[ii];
		ii++;

	}


	return (ptr);


}
