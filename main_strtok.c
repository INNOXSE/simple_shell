#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * path_print - Print directories in the PATH environment variable
 */
void path_print(void)
{
	char *path_env = getenv("PATH");  /* Get the value of the PATH environment variable */
	if (path_env == NULL)
	{
		printf("PATH environment variable not found\n");
		return;
	}

	char *path_copy = strdup(path_env);  /* Create a copy of the PATH string */
	if (path_copy == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}

	char *directory = strtok(path_copy, ":");  /* Tokenize the PATH string using ':' delimiter */
	while (directory != NULL)
	{
		printf("%s\n", directory);  /* Print each directory */
		directory = strtok(NULL, ":");
	}

	free(path_copy);  /* Free the memory allocated for the copy of the PATH string */
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

	return 0;
}
