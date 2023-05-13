#include "shell.h"

/**
 * main file - getroot and prints line
 * Return: 0 indicating successful
 */
int main (void)
{
	char *root = NULL;

	root = _getroot(stdin, root);

	printf("%s\n", root);

	fr(root);

	return (0);
}
