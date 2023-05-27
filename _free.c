#include "main.h"

/**
 * freeMain - Frees the array of tokens and the input
 * string in the main function
 *
 * @array_of_tokens: Tokenized string
 * @input: Input string
 *
 * Return: void
 */
void freeMain(char **array_of_tokens, char *input)
{
	int index;

	for (index = 0; array_of_tokens[index] != NULL; index++)
		free(array_of_tokens[index]);
	free(array_of_tokens);
	free(input);
}

/**
 * freeWhich - Frees the resources used in the 'which' function
 *
 * @path_var: Path variable
 * @array_of_tokens: Array of tokens
 *
 * Return: void
 */
void freeWhich(char **path_var, char **array_of_tokens)
{
	int index;

	if (array_of_tokens != NULL)
	{
		for (index = 0; array_of_tokens[index] != NULL; index++)
		{
			if (array_of_tokens[index] != NULL)
				free(array_of_tokens[index]);
		}
		free(array_of_tokens);
	}

	if (*path_var != NULL)
		free(*path_var);
}
