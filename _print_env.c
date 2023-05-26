#include "main.h"

/**
 * _print_env - Prints the environment variables
 *
 * Description: Prints all the environment variables to stdout
 *
 * Return: 0
 */
int _print_env(void)
{
	unsigned int environ_index;

	for (environ_index = 0; __environ[environ_index] != NULL; environ_index++)
		printf("%s\n", __environ[environ_index]);

	return 0;
}
