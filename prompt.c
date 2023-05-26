#include "shell.h"

/**
 * prompt - checks and prints prompt in interactive mode
 * @fp: file stream
 * @buf: buffer
**/
void prompt(int fp, struct stat buf)
{
	fstat(fp, &buf);

	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT);
}

/**
 * _puts - prints a string without a newline character
 * @str: string to print
 * Return: void
 */
void _puts(char *str)
{
	unsigned int length;

	length = _strlen(str);

	write(STDOUT_FILENO, str, length);
}
