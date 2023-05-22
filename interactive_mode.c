#include "main.h"

/**
 * interactive_mode - executes when programing
 * is running in interactive mode
 * @argv: command line arguments
 * Return: nothing
 */

void interactive_mode(char *argv[])
{
	char buffer[1024];
	char *args[64];
	char *prompt = "#cisfun$ ";
	char *tk;
	int i = 0;

	while (true)
	{
		print_prompt(prompt);
		if (fgets(buffer, 1024, stdin) == NULL)
		{
			_putchar('\n');
			/* if end of file (EOF) is encountered - CTRL + D */
			break;
		}

		/* tokenize input commands */
		tk = strtok(buffer, " \n");
		i = 0;
		while (tk != NULL && i < 64)
		{
			args[i] = tk;
			tk = strtok(NULL, " \n");
			i++;
		}

		/* set the last element of args to NULL */
		args[i] = NULL;

		execute_command(args, argv);
	}
}
