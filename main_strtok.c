#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * path_print - Print directories in the PATH environment variable
 */
void path_print(void)
{
	char *path_env = getenv("PATH");

	if (path_env == NULL)
	{
		printf("PATH environment variable not found\n");
		return;
	}

	char *path_copy = strdup(path_env);

	if (path_copy == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}

	char *directory = strtok(path_copy, ":");

	while (directory != NULL)
	{
		printf("%s\n", directory);
		directory = strtok(NULL, ":");
	}

	free(path_copy);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	path_print();

	return (0);
}
