#include "shell.h"
/**
 * _convert - searches dirs. in location var. for cmd
 * @cmd: to search for
 * @reach: reach of cmd to exe.
 * @location: reach var.
 * Return: pointer to reach
 */
char *_convert(char *cmd, char *reach, char *location)
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
		reach = malloc(sizeof(char) * (location_length + cmd_length) + 2);
		if (reach == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(reach, toks);
		reach[location_length] = '/';
		_strcpy(reach + location_length + 1, cmd);
		reach[location_length + cmd_length + 1] = '\0';
		if (access(reach, X_OK) != 0)
		{
			malloc(reach);
			reach = NULL;
			toks = strtok(NULL, ":");
		}
		else
			break;
	}
	malloc(location_copy);
	return (reach);
}
