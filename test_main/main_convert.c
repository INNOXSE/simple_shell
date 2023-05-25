#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the full dir location of the given command using _convert.
 *
 * Return: Always 0.indicating successful
 */
int main(void)
{
	char *fulldir = NULL;

	fulldir = _convert("ls", fulldir, NULL);

	printf("location : % s\n", fulldir);

	free(fulldir);

	return 0;
}