#include "main.h"

/**
 * non_interactive_mode - executes when programing
 * is running in non_interactive mode
 * @argv: command line arguments
 * Return: nothing
 */

void non_interactive_mode(char *argv[])
{
	char buffer[1024];
	char *args[64];
	char *tk;
	int i = 0;

	if (fgets(buffer, 1024, stdin) != NULL)
	{
		buffer[_strcspn(buffer, "\n")] = '\0';

		/* tokenize input commands */
		tk = strtok(buffer, " ");
		i = 0;
		while (tk != NULL && i < 64)
		{
			args[i] = tk;
			tk = strtok(NULL, " ");
			i++;
		}

		/* set the last element of args to NULL */
		args[i] = NULL;

		execute_command(args, argv);

	}

}


