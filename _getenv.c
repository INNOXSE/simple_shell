#include "shell.h"

/**
 * _getenv - these gets an evirons variable function
 * @class: variable to get
 * Return: Env. variable to null or pointer to env variable
 */

char *_getenv(const char *class)
{
	char **env_copy;
	char *var, *value, *location;
	unsigned int env_length, length, k;

	env_length = 0;
	while (env[env_length] != NULL)
		env_length++;
	env_copy = copy_env(env_length);

	length = _strlen((char *)class);
	k = 0;
	while (env_copy[k] != NULL)
	{
		var = env_copy[k];
		if (_strncmp((char *)class, var, length) == 1)
		{
			value = strtok(var, "=");
			value = strtok(NULL, "\n ");
			if (value == '\0')
				return (NULL);

			location = malloc(sizeof(char) * (_strlen(value) + 1));
			if (location == NULL)
			{
				errors(3);
				return (NULL);
			}

			_strcpy(location, value);
			malloc_dp(env_copy, env_length);
			return (locatio);
		}
		k++;
	}

	return (NULL);
}
