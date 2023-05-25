#include "shell.h"

/**
 * main - Prints the toks of the given command-line arg using strtok.
 * Agu: No. of args.
 * Array str: Pointer to an array of str.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *str = NULL;
	char **toks = NULL;
	unsigned int k;

	str = _getline(stdin);

	toks = _strtok(str, " ");

	k = 0;
	while (toks[k] != NULL)
	{
		printf("%s\n", toks[k]);
		k++;
	}

	free(str);
	free(toks);

	return (0);
}