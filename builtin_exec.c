#include "shell.h"
/**
**builtin_exec - exec. the built in functs
**@token: arg being passed
**Return: toks
**/
int builtin_exec(char **toks)
{
	int stat;
	unsigned int length;
	unsigned int digit;
	unsigned int k;

	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (toks[0] == NULL)
		return (1);

	length = _strlen(toks[0]);

	digit = shell_digit_builtins(builtin);
	for (k = 0; k < digit; k++)
	{
		if (_strcmp(toks[0], builtin[k].class, length) == 0)
		{
			stat = (builtin[k].p)();
			return (stat);
		}
	}
	return (1);
}

/**
**shell_digit_builtin - this check digit built-in
**@builtin: to be counted
**Return: digit of built-in
**/

int shell_digit_builtins(built_s builtin[])
{
	unsigned int k;

	k = 0;
	while (builtin[k].class != NULL)
		k++;

	return (k);
}
