#include "shell.h"

/**
 * io - checks mode and prints prompt if in interactive mode
 * @fd: file stream
 * @buf: buffer
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
