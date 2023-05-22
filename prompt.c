#include "main.h"

/**
 * print_prompt - prints the shell prompt
 * @prompt: prompt characters
*/

void print_prompt(const char *prompt)
{
	int pi = 0;

	while (prompt[pi] != '\0')
	{
		_putchar(prompt[pi]);
		pi++;
	}
}
