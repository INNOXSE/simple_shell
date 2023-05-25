#include "shell.h"

/**
 * _strcmp - compares two strings to find out if they are exactly the same
 * @class: class supplied by user to search for
 * @var: var to compare against
 * @lenght: lenght of class
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strcmp(char *class, char *var, unsigned int length)
{
	unsigned int var_length;
	unsigned int k;

	var_length = _strlen(var);
	if (var_length != length)
		return (-1);

	k = 0;
	while (class[k] != '\0' && var[k] != '\0')
	{
		if (class[k] != var[k])
			return (1);
		k++;
	}
	return (0);
}

/**
 * _strncmp - compares 2 strings
 * up to given len are the same
 * @class: class supply by user to search for
 * @var: var to compare against
 * @len: len to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *class, char *var, unsigned int length)
{
	unsigned int k;

	k = 0;
	while (k < length)
	{
		if (class[k] != var[k])
			return (-1);
		k++;
	}
	return (1);
}

/**
 * *_strcpy - copied string pointed to by src to the buffer pointed to endpoint
 * @endpoint: string destination
 * @src: string source
 * Return: the pointer to endpoint
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
 * _strlen - returns the len of a string
 * @s: str to be evaluated
 * Return: len of string
 */
int _strlen(char *s)
{
	int k = 0;

	while (s[k] != '\0')
		k++;

	return (k);
}
