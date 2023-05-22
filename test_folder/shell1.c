#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void printErrorMessage(const char* programName, const char* message) {
    fprintf(stderr, "%s: %s\n", programName, message);
}

int isInteractive() {
    return isatty(fileno(stdin));
}

int main(int __attribute__((unused)) argc, char *argv[]) {
    char buffer[1024];
    char *args[64];
    char *env[] = {NULL};
    char *prompt = "#cisfun$ ";

    if (isInteractive()) {
        while (true) {
            int pi = 0;

            while (prompt[pi] != '\0') {
                putchar(prompt[pi]);
                pi++;
            }

            if (fgets(buffer, 1024, stdin) == NULL) {
                putchar('\n');
                /* if end of file (EOF) is encountered - CTRL + D */
                break;
            }

            char *tk = strtok(buffer, " \n");
            int i = 0;

            while (tk != NULL && i < 64) {
                args[i] = tk;
                tk = strtok(NULL, " \n");
                i++;
            }

            if (i != 1 || args[0][0] == '-') {
                printErrorMessage(argv[0], "Invalid command");
                continue;
            }

            args[i] = NULL;
            pid_t child_pid = fork();

            if (child_pid == -1) {
                perror("Error");
                exit(EXIT_FAILURE);
            } else if (child_pid == 0) {
                /* child process */
                if (execve(args[0], args, env) == -1) {
                    printErrorMessage(argv[0], "No such file or directory");
                }
                exit(EXIT_FAILURE);
            } else {
                /* parent process */
                int status;
                wait(&status);
            }
        }
    } else {
        if (fgets(buffer, 1024, stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline character

            char *tk = strtok(buffer, " ");
            int i = 0;

            while (tk != NULL && i < 64) {
                args[i] = tk;
                tk = strtok(NULL, " ");
                i++;
            }

            if (i != 1 || args[0][0] == '-') {
                printErrorMessage(argv[0], "Invalid command");
                return 1;
            }

            args[i] = NULL;
            pid_t child_pid = fork();

            if (child_pid == -1) {
                perror("Error");
                exit(EXIT_FAILURE);
            } else if (child_pid == 0) {
                /* child process */
                if (execve(args[0], args, env) == -1) {
                    printErrorMessage(argv[0], "No such file or directory");
                }
                exit(EXIT_FAILURE);
            } else {
                /* parent process */
                int status;
                wait(&status);
            }
        }
    }

    return 0;
}

