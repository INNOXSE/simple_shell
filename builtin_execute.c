#include "shell.h"
/**
**builtin_execute - executes the built in functions
**@tokens: arguments being passed
**Return: tokens
**/
int builtin_execute(char **tokens)
{
	int status;
	unsigned int length;
	unsigned int num;
	unsigned int k;

	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (tokens[0] == NULL)
		return (1);

	length = _strlen(tokens[0]);

	num = shell_num_builtins(builtin);
	for (k = 0; k < num; k++)
	{
		if (_strcmp(tokens[0], builtin[k].name, length) == 0)
		{
			status = (builtin[k].p)();
			return (status);
		}
	}
	return (1);
}

/**
**shell_num_builtins - this check number in built-ins
**@builtin: takes the builtin to be counted
**Return: num of built-ins
**/

int shell_num_builtins(built_s builtin[])
{
	unsigned int k;

	k = 0;
	while (builtin[k].name != NULL)
		k++;

	return (k);
}
