#include "shell.h"

/**
 * main file - getline and prints line
 * Return: 0 indicating successful
 */
int main (void)
{
	char *line = NULL;

	line = _getline(stdin, line);

	printf("%s\n", line);

	free(line);

	return (0);
}
