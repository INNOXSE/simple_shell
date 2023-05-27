#include "main.h"

/**
 * create_envar - Create an environment variable string.
 * @env_var: Pointer to the environment variable string.
 * @envar_length: Length of the environment variable string.
 * @name: Name string.
 * @value: Value string.
 *
 * Return: None.
 */
void create_envar(char **env_var, unsigned int envar_length, const char *name,
		const char *value)
{
	*env_var = malloc_char(env_var, envar_length,
				"_setenv() Error: env_var malloc failed");
	envar_length = strlen(name) + strlen(value) + 2;
	*env_var = malloc_char(env_var, envar_length,
				"_setenv() Error: env_var malloc failed");
	strcpy(*env_var, name);
	strcat(*env_var, "=");
	strcat(*env_var, value);
	strcat(*env_var, "\0");
}

/**
 * _env_set_exists - Check if an environment
 * variable exists and update it if necessary.
 * @env_var: Pointer to the environment variable string.
 * @envar_length: Length of the environment variable string.
 * @name: Name string.
 * @overwrite: Overwrite integer.
 *
 * Return: 0 on success, -1 on failure.
 */
int _env_set_exists(char *env_var, unsigned int envar_length, const char *name,
		    int overwrite)
{
	unsigned int env_index;

	for (env_index = 0; __environ[env_index]; env_index++)
	{
		if (strncmp(__environ[env_index], name, strlen(name)) == 0 && overwrite != 0)
		{
			free(__environ[env_index]);
			__environ[env_index] = malloc(sizeof(char) * envar_length);
			if (__environ[env_index] == NULL)
			{
				perror("_setenv() Error: __environ[env_index] malloc failed");
				free(env_var);
				return (-1);
			}
			strcpy(__environ[env_index], env_var);
			free(env_var);
			return (0);
		}
	}
	return (0);
}

/**
 * env_does_not_exists - Handle the case when
 * the environment variable does not exist.
 * @env_var: Pointer to the environment variable string.
 * @envar_length: Length of the environment variable string.
 * @env_length: Length of the environment.
 *
 * Return: 0 on success, -1 on failure.
 */
int env_does_not_exists(char *env_var, unsigned int envar_length,
			unsigned int env_length)
{
	unsigned int free_new_env_index;
	char **new_environ;

	new_environ = (char **)malloc(sizeof(char *) * (env_length + 2));
	if (new_environ == NULL)
	{
		perror("_setenv() Error: new_environ malloc failed");
		free(env_var);
		return (-1);
	}
	copy_array(new_environ, __environ);
	new_environ[env_length] = malloc(sizeof(char) * envar_length);
	if (new_environ[env_length] == NULL)
	{
		perror("_setenv() Error: new_environ[env_index] malloc failed");
		for (free_new_env_index = 0; free_new_env_index < env_length;
		     free_new_env_index++)
			free(new_environ[free_new_env_index]);
		free(new_environ);
		free(env_var);
		return (-1);
	}
	strcpy(new_environ[env_length], env_var);
	new_environ[env_length + 1] = NULL;
	free(env_var);
	__environ = new_environ;
	return (0);
}
/**
 * _setenv - Set an environment variable.
 * @name: Name of the variable.
 * @value: Value of the variable.
 * @overwrite: Overwrite flag.
 *
 * Description: This function adds the variable name to the environment with
 * the value value, if name does not already exist. If name already exists and
 * overwrite is nonzero, the value is changed. If overwrite is zero, the value
 * is not changed. This function makes copies of the strings pointed to by name
 * and value. The unsetenv() function can be used to delete a variable.
 *
 * Return: 0 on success, -1 on failure.
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	unsigned int envar_length;
	char *env_var;

	envar_length = strlen(name) + strlen(value) + 2;
	create_envar(&env_var, envar_length, name, value);
	_env_set_exists(env_var, envar_length, name, overwrite);
	if (_env_name_exists(name) != -1)
		_env_set_exists(env_var, envar_length, name, overwrite);
	else
		env_does_not_exists(env_var, envar_length, _env_length());

	return (0);
}
