#include "shell.h"

/**
 * tokenizer - tokenizes a string
 * @str: input string
 * Return: pointer to array of tokens
 */
char **tokenizer(char *str)
{
	char **toks;
	char *token;
	unsigned int k = 0;

	toks = malloc(sizeof(char *) * BUFFER);
	if (toks == NULL)
	{
		errors(3);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, " \t\n\r");
	while (token != NULL)
	{
		toks[k] = token;
		token = strtok(NULL, " \t\n\r");
		k++;
	}

	toks[k] = NULL;

	return (toks);
}
