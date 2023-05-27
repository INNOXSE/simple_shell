#include "main.h"

/**
 * is_builtin - Check if a command is a built-in command.
 * @array_of_tokens: Command array.
 *
 * Description: This function checks if the first token in the command array
 * matches any of the built-in commands defined in the `builtins` array.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int is_builtin(char **array_of_tokens)
{
	int builtin_index;
	const struct builtin_command builtins[] = {
		{"env", _env_builtin},
		{"exit", _exit_builtin},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (builtin_index = 0; builtins[builtin_index].name != NULL; builtin_index++)
	{
		if (strcmp(array_of_tokens[0], builtins[builtin_index].name) == 0)
			return (1);
	}

	return (0);
}

/**
 * builin_handler - Handle a built-in command.
 * @array_of_tokens: Command array.
 *
 * Description: This function executes the appropriate built-in command based
 * on the first token in the command array. It looks for a matching command in
 * the `builtins` array and calls the corresponding function.
 *
 * Return: The return value of the executed built-in command,
 * or 0 if the command
 * is not a built-in or if there was an error.
 */
int builin_handler(char **array_of_tokens)
{
	int builtin_index;
	const struct builtin_command builtins[] = {
		{"env", _env_builtin},
			{"exit", _exit_builtin},
			{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (builtin_index = 0; builtins[builtin_index].name != NULL; builtin_index++)
	{
		if (strcmp(array_of_tokens[0], builtins[builtin_index].name) == 0)
			return (builtins[builtin_index].function(array_of_tokens));
	}

	return (0);
}
