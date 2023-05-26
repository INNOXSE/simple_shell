#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * shell_exit - exits the shell
 * Return: -1
 */
int shell_exit(void)
{
	return (-1);
}

/**
 * shell_env - prints the environment
 * Return: 0 on success
 */
int shell_env(void)
{
	unsigned int k = 0;

	while (environ[k] != NULL)
	{
		write(STDOUT_FILENO, environ[k], _strlen(environ[k]));
		write(STDOUT_FILENO, "\n", 1);
		k++;
	}

	return (0);
}
