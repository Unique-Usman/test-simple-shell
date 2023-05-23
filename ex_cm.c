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
    char *env[] = { NULL };
    pid_t child_pid;
    int status;
	const char *path; //added const here, the variable that recieve the return must not be muted directly
	char *token;
	char command_path[1024];
	int command_found;

	if (strchr(args[0], '/') == NULL) {
        /* Command doesn't contain a slash, so search in PATH */
        path = getenv("PATH");
        command_path[1024];
        command_found = 0;
        char *tmp_path = malloc(sizeof(char) * (strlen(path) + 1)); //creating tmp_path to avoid changing the value of the path
	strcpy(tmp_path, path);
        token = strtok(tmp_path, ":"); //used the tmp_path here
        while (token != NULL) {
            strcpy(command_path, token);
            strcat(command_path, "/");
            strcat(command_path, args[0]);
            if (access(command_path, X_OK) == 0) {
                // Command found in PATH, execute it
                args[0] = strdup(command_path);
                command_found = 1;
                break;
            }
            token = strtok(NULL, ":");
        }
        
        if (!command_found) {
            perror(argv[0]);
            return;
        }
    }

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

