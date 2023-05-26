#include "shell.h"

/**
 * free_all - fr all malloc'd space at end of main loop
 * @tokens: pointer towards token array
 * @path: pointer to path var
 * @line: pointer to userinput buf
 * @fullpath: pointer to full path
 * @flag: flag marking if full_path was malloc'd
 * Return: void
 */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag)
{
	free(path);
	free(tokens);
	free(line);
	if (flag == 1)
		free(fullpath);
}

/**
 * free_dp - free double pointer
 * @array: double pointer to free
 * @length: length of double pointer
 * Return: void
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
