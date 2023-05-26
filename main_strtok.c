#include "shell.h"
/**
 * main - uses strtok to print tokens
 * ac: number of arguments
 * av: pointer to array of strings
 * Return: 0 on success
 */

int main(void)
{
	char *str = NULL;
	char **tokens = NULL;
	unsigned int k;

	str = _getline(stdin, str);

	tokens = _strtok(str, tokens);

	k = 0;
	while (tokens[k] != NULL)
	{
		printf("%s\n", tokens[k]);
		k++;
	}

	free(str);
	free(tokens);

	return (0);
}
