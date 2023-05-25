#include "shell.h"

/**
 * prompt - checks and prints prompt in interactive mode
 * @fd: file stream
 * @buf: buff
**/
void prompt(int fp, struct stat buf)
{
	fstat(fp, &buf);

	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT);
}

/**
 * _puts - prints a string without a \n
 * @str: string to print
 * Return: void
 */
void _puts(char *str)
{
	unsigned int lenght;

	lenght = _strlen(str);

	write(STDOUT_FILENO, str, lenght);
}
