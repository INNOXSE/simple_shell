#include "shell.h"

/**
 * _getline - input from user into buffer line
 * @fp: buffer 4 user input
 * Return: buff with ui
 */
char *_getline(FILE *fp)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;
	read = getline(&line, &len, fp);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
