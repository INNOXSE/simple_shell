#include "main.h"

/**
 * _env_builtin - Prints the environment variables
 *
 * @array_of_tokens: Command array (unused)
 *
 * Return: 1 for success, 0 for failure
 */
int _env_builtin(char **array_of_tokens __attribute__((unused)))
{
	int environment_index;

	for (environment_index = 0; __environ[environment_index]; environment_index++)
	{
		write(STDOUT_FILENO, __environ[environment_index],
				strlen(__environ[environment_index]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}

	return environment_index;
}
