#include "shell.h"

/**
 * tokenizer - string tokenization
 * @str: userinput
 * Return: pointer to token array
 */
char **tokenizer(char *str)
{
	char **tokens;
	char *token;
	unsigned int k;

	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		errors(3);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, "\n\t\r ");

	k = 0;
	while (token != NULL)
	{
		tokens[k] = token;
		token = strtok(NULL, "\n\t\r ");
		k++;
	}

	tokens[k] = NULL;

	return (tokens);
}
