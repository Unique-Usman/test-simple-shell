#include "main.h"

/**
 * main - Entry point
 * @argc: number of command line argument
 * @argv: array of command line arguments
 * Return: Always 0 on success
 */

int main(int __attribute__((unused)) argc, char *argv[])
{
	if (check_mode())
	{
		interactive_mode(argv);
	}
	else
	{
		non_interactive_mode(argv);
	}


	return (0);
}
