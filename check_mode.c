#include "main.h"

/**
 * check_mode - uses isatty() to check if the
 * program is running in a terminal (interactive mode) or if
 * input is coming from a pipe or file (non interactive mode)
 * Return: 1 if fd is an open file descriptor referring to a terminal
 * otherwise 0 is returned
 */

int check_mode(void)
{
	return (isatty(STDIN_FILENO));
}
