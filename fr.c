#include "shell.h"

/**
 * free_all - frees all malloc'd space at end of main loop
 * @toks: pointer to tokens array
 * @location: pointer to location var
 * @line: pointer to user input buffer
 * @fulldir: pointer to fulldir
 * @time: time marking fulldir was malloc'd
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
 * free_dp - free double pointer
 * @arry: double pointer to free
 * @length: length of double pointer
 * Return: void on success
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int k;

	k = 0;
	while (k < length)
	{
		free(array[k]);
		k++;
	}
	free(array);
}