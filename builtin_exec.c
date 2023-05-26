#include "shell.h"

/**
 * builtin_execute - executes the built-in functions
 * @toks: array of tokens
 * Return: 0 if successful, 1 otherwise
 */
int builtin_execute(char **toks, built_t *builtin)
{
	int status;
	unsigned int length;
	unsigned int num_builtins;
	unsigned int k;

	struct built_t builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (toks[0] == NULL)
		return (1);

	length = _strlen(toks[0]);
	num_builtins = shell_digit_builtins(builtin);

	for (k = 0; k < num_builtins; k++)
	{
		if (_strcmp(toks[0], builtin[k].name, length) == 0)
		{
			status = (builtin[k].p)();
			return (status);
		}
	}

	return (1);
}

/**
 * shell_digit_builtins - counts the number of built-in functions
 * @builtin: array of built-in functions
 * Return: number of built-in functions
 */
unsigned int shell_digit_builtins(built_t *builtin[])
{
	unsigned int k = 0;

	while (builtin[k].name != NULL)
		k++;

	return (k);
}

