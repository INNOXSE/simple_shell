#include "holberton.h"

/**
 * main - uses strtok to print tokens
 * @ac: number of arguments
 * @av: pointer to array of strings
 * Return: 0 on success
 */
int main(void)
{
<<<<<<< HEAD
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
=======
	char *str = NULL;
	char **tokens = NULL;
	unsigned int k;

	str = _getline(stdin, str);

	tokens = _strtok(str, tokens);

	k = 0;
	while (tokens[k] != NULL)
	{
		printf("%s\n", tokens[i]);
		k++;
	}

	free(str);
	free(tokens);
>>>>>>> c9e95f35ae2db57d52d2eaef01cc73db1b6f6245

	return (0);
}
