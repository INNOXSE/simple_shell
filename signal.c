#include "main.h"

/**
 * sigint_handler - handles the SIGINT signal
 * @signal: the signal number
 *
 * Return: void
 */
void sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();
		fflush(stdout);
	}
}
