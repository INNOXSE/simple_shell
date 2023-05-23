#include "shell.h"
/**
**shell_exit - exits the header
**Return: void on success
**/

	int shell_exit(void)
	{
		return (-1);
	}


/**
**shell_env - prts env.
**Return: void on success
**/

	int shell_env(void)
	{
		unsigned int k;

		k = 0;
		while (env[k] != NULL)
		{
			write(STDOUT_FILENO, env[k], _strlen(env[k]));
			write(STDOUT_FILENO, "\n", 1);
			k++;
		}
		return (0);
	}
