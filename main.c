#include "main.h"

/**
 * main - Entry point of the program
 *
 * Description: This is the main function that
 * executes the shell program.
 * It reads user input, tokenizes it, and executes
 * the corresponding commands.
 *
 * @ac: The number of command-line arguments
 * @arvs: Array of command-line arguments
 * @envp: Array of environment variables
 *
 * Return: The exit status of the program
 */
int main(__attribute((unused)) int ac,
		__attribute((unused)) char **arvs,
		__attribute((unused)) char **envp)
{
	int status = 0;
	char *input, *delimiter, *which;
	size_t number_of_malloc_bytes_allocated, command_num;
	char **array_of_tokens;

	signal(SIGINT, sigint_handler);
	input = NULL;
	number_of_malloc_bytes_allocated = command_num = 0;
	delimiter = " \n";
	while (1)
	{
		command_num++;
		_getline(&input, &number_of_malloc_bytes_allocated, status);
		array_of_tokens = array_maker(input, delimiter);
		if (!(*array_of_tokens))
			status = 0;
		else
		{
			if (is_builtin(array_of_tokens))
			{
				if (builin_handler(array_of_tokens) == EXIT_CODE)
				{
					free_main(array_of_tokens, input);
					exit(status);
				}
			}
			else
			{
				which = _which(array_of_tokens[0]);
				if (which !=  NULL)
					status = _fork(which, array_of_tokens);
				else
					status = error_not_found(arvs, array_of_tokens, command_num);
			}
		}
		free_main(array_of_tokens, input);
		input = NULL;
	}
	return (0);
}
