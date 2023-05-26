#include "shell.h"

/**
 * _strcmp - compares similarity of strings 
 * @name: user name supplied to be searched
 * @variable: var to compare against
 * @length: length of name
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strcmp(char *name, char *variable, unsigned int length)
{
	unsigned int var_length;
	unsigned int k;

	var_length = _strlen(variable);
	if (var_length != length)
		return (-1);

	k = 0;
	while (name[k] != '\0' && variable[k] != '\0')
	{
		if (name[k] != variable[k])
			return (1);
		k++;
	}
	return (0);
}

/**
 * _strncmp - compares two strings
 * up to given length are the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *name, char *variable, unsigned int length)
{
	unsigned int k;

	k = 0;
	while (k < length)
	{
		if (name[k] != variable[k])
			return (-1);
		i++;
	}
	return (1);
}

/**
 * *_strcpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @src: string source
 * Return: the pointer to dest
 */
char *_strcpy(char *endpoint, char *src)
{
	int k;
	int s = _strlen(src);

	for (k = 0; k <= s; k++)
		endpoint[k] = src[k];

	return (endpoint);
}
/**
 * _strlen - returns the length of a string
 * @s: string to be evaluated
 * Return: length of string
 */
int _strlen(char *s)
{
	int k = 0;

	while (s[k] != '\0')
		k++;

	return (k);
}
