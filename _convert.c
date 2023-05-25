#include "shell.h"
/**
 * _convert - searches dirs. in location var. for cmd
 * @cmd: to search for
 * @fulldir: fulldir of command to exe.
 * @location: fulldir var.
 * Return: pointer to fulldir
 */
char *_convert(char *command, char *fulldir, char *location)
{
	unsigned int command_length, location_length, original_location_length;
	char *location_copy, *toks;

	command_length = _strlen(command);
	original_location_length = _strlen(location);
	location_copy = malloc(sizeof(char) * original_location_length + 1);
	if (location_copy == NULL)
	{
		errors(3);
		return (NULL);
	}
	_strcpy(location_copy, location);
	/* copy location dir. + command name and check if it exists */
	toks = strtok(location_copy, ":");
	if (toks == NULL)
		toks = strtok(NULL, ":");
	while (toks != NULL)
	{
		location_length = _strlen(toks);
		fulldir = malloc(sizeof(char) * (original_location_length + command_length) + 2);
		if (fulldir == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(fulldir, toks);
		fulldir[location_length] = '/';
		_strcpy(fulldir + location_length + 1, command);
		fulldir[location_length + command_length + 1] = '\0';
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
