#include "shell.h"
/**
 * _convert - searches dirs. in location var. for cmd
 * @cmd: to search for
 * @fulldir: fulldir of cmd to exe.
 * @location: fulldir var.
 * Return: pointer to fulldir
 */
char *_convert(char *cmd, char *fulldir, char *location)
{
	unsigned int cmd_length, location_length, original_location_length;
	char *location_copy, *toks;

	cmd_length = _strlen(cmd);
	original_location_length = _strlen(location);
	location_copy = malloc(sizeof(char) * original_location_length + 1);
	if (location_copy == NULL)
	{
		errors(3);
		return (NULL);
	}
	_strcpy(location_copy, location);
	/* copy location dir. + cmd class and check if it exists */
	toks = strtok(location_copy, ":");
	if (toks == NULL)
		toks = strtok(NULL, ":");
	while (toks != NULL)
	{
		location_length = _strlen(toks);
		fulldir = malloc(sizeof(char) * (location_length + cmd_length) + 2);
		if (fulldir == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(fulldir, toks);
		fulldir[location_length] = '/';
		_strcpy(fulldir + location_length + 1, cmd);
		fulldir[location_length + cmd_length + 1] = '\0';
		if (access(fulldir, X_OK) != 0)
		{
			free(fulldir);
			fulldir = NULL;
			toks = strtok(NULL, ":");
		}
		else
			break;
	}
	free(location_copy);
	return (fulldir);
}
