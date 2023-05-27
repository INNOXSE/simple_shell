#include "main.h"

/**
 * _getenv - Retrieves the value of an environment variable
 *
 * @name: Name of the environment variable
 *
 * Return: Value of the environment variable, or NULL if not found
 */
char *_getenv(const char *name)
{
	unsigned int env_index, envar_length;
	char *env_var;
	char *env_var_cpy;

	for (env_index = 0; __environ[env_index] != NULL; env_index++)
	{
		if (strncmp(__environ[env_index], name, strlen(name)) == 0)
		{
			envar_length = strlen(__environ[env_index]) - strlen(name);
			env_var = malloc(sizeof(char) * (envar_length + 1));
			if (env_var == NULL)
			{
				perror("_getenv() Error: env_var malloc failed");
				return (NULL);
			}
			malloc_char(&env_var_cpy, strlen(__environ[env_index]) + 1,
					"_getenv() malloc error");
			strcpy(env_var_cpy, __environ[env_index]);
			strncpy(env_var, env_var_cpy + strlen(name), envar_length);
			env_var[envar_length] = '\0';
			free(env_var_cpy);
			return (env_var);
		}
	}
	return (NULL);
}
