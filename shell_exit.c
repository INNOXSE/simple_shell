#include "shell.h"

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
		_puts(environ[k]);
		_putchar('\n');
		k++;
	}

	return (0);
}
