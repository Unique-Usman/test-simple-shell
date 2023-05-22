#include "main.h"

/**
 * main - Entry point
 * Return: Always 0.
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char buffer[1024];
	char *args[64];
	char *env[] = {NULL};
	char *prompt = "#cisfun$ ";
	int pi = 0;
	char *tk;
	int i;
	pid_t child_pid;
	int status;

	while (true)
	{

	while (prompt[pi] != '\0')
	{
		_putchar(prompt[pi]);
		pi++;
	}
	pi = 0;

	if (fgets(buffer, 1024, stdin) == NULL)
	{
		_putchar('\n');
		/*if end of file (EOF) is encounted - CTRL + D*/
		break;
	}
	/*tokenize input commands*/
	tk = strtok(buffer, " \n");
	i = 0;
	while (tk != NULL && i < 64)
	{
		args[i] = tk;
		tk = strtok(NULL, " \n");
		i++;
	}
	/** if (i != 1 || args[0][0] == '-')
	{
		perror(argv[0]);
		continue;
	} */
	/* set the last element of args to NULL*/
	args[i] = NULL;
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
		/*parent process*/
		wait(&status);
	}
	}
	return (0);
}
