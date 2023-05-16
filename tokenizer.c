#include "shell.h"

/**
 * tokenizer - tokenizes str
 * @str: input user
 * Return: pointr to array of toks
 */
char **tokenizer(char *str)
{
	char **toks;
	char *tokenz;
	unsigned int k;

	toks = malloc(sizeof(char) * BUFFER);
	if (toks == NULL)
	{
		errors(3);
		exit(EXIT_FAILURE);
	}

	tokenz = strtok(str, "\n\t\r ");

	k = 0;
	while (tokenz != NULL)
	{
		toks[k] = tokenz;
		tokenz = strtok(NULL, "\n\t\r ");
		k++;
	}

	toks[k] = NULL;

	return (toks);
}
