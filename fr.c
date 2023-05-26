#include "shell.h"

/**
 * free_all - frees all dynamically allocated memory
 * @toks: pointer to tokens array
 * @location: pointer to location string
 * @line: pointer to user input buffer
 * @fulldir: pointer to fulldir string
 * @time: flag indicating if fulldir was dynamically allocated
 * Return: void
 */
void free_all(char **toks, char *location, char *line, char *fulldir, int time)
{
	free(location);
	free(toks);
	free(line);
	if (time == 1)
		free(fulldir);
}

/**
 * free_dp - frees a double pointer
 * @array: double pointer to free
 * @length: length of double pointer
 * Return: void
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int k = 0;

	while (k < length)
	{
		free(array[k]);
		k++;
	}
	free(array);
}
