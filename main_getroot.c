#include "shell.h"

/**
 * main file - getline and prints line
 * Return: 0 indicating successful
 */
int main (void)
{
	char *line = NULL;

	root = _getline(stdin, root);

	printf("%s\n", line);

	fr(line);

	return (0);
}
