#include "shell.h"

/**
 * main - Prints the full dir location of the given command using _convert.
 *
 * Return: Always 0.indicating successful
 */
int main(void)
{
	char *reach = NULL;

	reach = _convert("ls", reach);

	printf(location : % s\n",reach);

	fr(reach);

	return (0);
}
