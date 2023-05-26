#include "shell.h"
/**
**shell_exit - exits the simple shell
**Return: void
**/

	int shell_exit(void)
	{
		return (-1);
	}


/**
**shell_env - prts environs
**Return: void
**/

	int shell_env(void)
	{
		unsigned int k;

		k = 0;
		while (environ[k] != NULL)
		{
			write(STDOUT_FILENO, environ[k], _strlen(environ[k]));
			write(STDOUT_FILENO, "\n", 1);
			k++;
		}
		return (0);
	}
