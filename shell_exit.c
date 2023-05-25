#include "shell.h"
char **environ;  /* Declaration of the external environment variable*/
char **environ = NULL;      /*Definition of the env variable*/

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
		while (environ[k] != NULL)
		{
			write(STDOUT_FILENO, environ[k], _strlen(environ[k]));
			write(STDOUT_FILENO, "\n", 1);
			k++;
		}
		return (0);
	}
