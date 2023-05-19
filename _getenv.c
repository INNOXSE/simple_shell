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
			fr_dp(env_copy, env_length);
			return (location);
		}
		k++;
	}

	return (NULL);
}

/**
 * copy_env - Makes a copy of the environment variable.
 *
 * @env_copy: Pointer to the copy of the environment variable.
 * @env_length: Length of the environment variable.
 *
 * Return: Double pointer to the copy of env  var.
 */
char **copy_env(char **env_copy, unsigned int env_length)
{
	char *var;
	unsigned int var_length;
	unsigned int k;

	env_copy = malloc(sizeof(char **) * (env_length));
	if (env_copy == NULL)
	{
		errors(3);
		return (NULL);
	}

	k = 0;
	while (k < env_length)
	{
		var = env[k];
		var_length = _strlen(var);

		env_copy[i] = malloc(sizeof(char) * var_length + 1);
		if (env_copy[k] == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(env_copy[k], env[k]);
		k++;
	}

	return (env_copy);
}
