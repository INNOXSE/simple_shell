#include "shell.h"

/**
 * _strcmp - compares two strings to check if they are equal
 * @name: first string
 * @var: second string
 * @length: length of string to compare
 * Return: 0 if strings are equal, 1 otherwise
 */
int _strcmp(char *name, char *var, unsigned int length)
{
	unsigned int k = 0;

	while (k < length)
	{
		if (name[k] != var[k])
			return (1);
		k++;
	}

	return (0);
}

/**
 * _strncmp - compares two strings up to a given length
 * @name: first string
 * @var: second string
 * @length: length to compare up to
 * Return: 0 if strings are equal, 1 otherwise
 */
int _strncmp(char *name, char *var, unsigned int length)
{
	unsigned int k = 0;

	while (k < length)
	{
		if (name[k] != var[k])
			return (1);
		k++;
	}

	return (0);
}

/**
 * _strcpy - copies a string from source to destination
 * @destination: destination string
 * @source: source string
 * Return: pointer to destination string
 */
char *_strcpy(char *destination, char *source)
{
	unsigned int k = 0;

	while (source[k] != '\0')
	{
		destination[k] = source[k];
		k++;
	}
	destination[k] = '\0';

	return (destination);
}

/**
 * _strlen - returns the length of a string
 * @str: string to be evaluated
 * Return: length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}
