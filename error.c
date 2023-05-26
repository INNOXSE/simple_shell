#include "shell.h"

/**
 * errors - prints errors based on their case
 * @error: error number associated with perror statement
 * Return: void
 */
void errors(int error)
{
	switch (error)
	{
	case 1:
		_puts(ERR_FORK);
		perror("Error");
		exit(EXIT_FAILURE);

	case 2:
		perror("Error");
		exit(EXIT_FAILURE);

	case 3:
		_puts(ERR_MALLOC);
		exit(EXIT_FAILURE);

	case 4:
		_puts(ERR_PATH);
		exit(EXIT_FAILURE);

	default:
		return;
	}
}
