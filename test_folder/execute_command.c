#include "main.h"

/**
 * execute_command - creates a child process and executes
 * the program in the process
 * @args: array of commands passed to the child process
 * @argv: command line arguments
 * Return: nothing
 */
void execute_command(char *args[], char *argv[])
{
	char *env[] = {NULL};
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		 exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* child process */
		if (execve(args[0], args, env) == -1)
		{
			perror(argv[0]);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		/* parent process */
		wait(&status);
	}
}
