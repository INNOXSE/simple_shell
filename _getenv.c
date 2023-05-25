#include "shell.h"

/**
 * _getenv - Get an environment variable.
 * @class: Variable to get.
 *
 * Return: Pointer to the environment variable or NULL if not found.
 */
char *_getenv(const char *class)
{
	char **environ_copy;
	char *var, *value, *location;
	int compare;
	unsigned int location_length, length, k;

	environ_length = 0;
	while (environ[environ_length] != NULL)
		environ_length++;
	environ_copy = NULL;
	environ_copy = copy_env(environ_copy, environ_length);
	length = _strlen((char *)class);
	k = 0;
	while (environ_copy[k] != NULL)
	{
		var = environ_copy[k];
		compare = _strncmp((char *)class, var, length);
		if (compare == 1)
		{
			value = strtok(var, "=");
			value = strtok(NULL, "\n ");
			if (value == '\0')
			{
			errors(4);
			exit(EXIT_FAILURE);
			}
			location_length = _strlen(value);
			location = malloc(sizeof(char) * (_strlen(value) + 1));
			if (location == NULL)
			{
				errors(3);
				return (NULL);
}
			location = _strcpy(location, value);
			free_dp(environ_copy, environ_length);
			return (location);
		}
		k++;
	}
	return (NULL);
}

/**
 * copy_env - Make a copy of the environment var.
 * @environ_copy: Pointer to the copy of the env var.
 * @environ_length: Length of the env var.
 *
 * Return: Double pointer to the copy of env var.
 */
char **copy_env(char **environ_copy, unsigned int environ_length)
{
	char *var;
	unsigned int var_length;
	unsigned int k;

	environ_copy = malloc(sizeof(char *) * (environ_length));
	if (environ_copy == NULL)
	{
		errors(3);
		return (NULL);
	}
	k = 0;
	while (k < environ_length)
	{
		var = environ[k];
		var_length = _strlen(var);
		environ_copy[k] = malloc(sizeof(char) * (var_length + 1));
		if (environ_copy[k] == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(environ_copy[k], environ[k]);
		k++;
	}
	return (environ_copy);
}
