#include "shell.h"

/**
 * errors - prts errors based on thier case
 * @error: error no is assoc. with perror stmt
 * Return: void on indicated success
 */
void errors(int error)
{
	switch (error)
	{
	case 1: /* writes fork error to standarderror */
		write(STDERR_FILENO, ERR_FORK, _strlen(ERR_FORK));
		perror("Error");
		break;

	case 2: /* writes execve error to standarderrorderr */
		perror("Error");
		break;

	case 3: /* writes malloc error to stderr */
		write(STDERR_FILENO, ERR_MALLOC, _strlen(ERR_MALLOC));
		break;
	case 4: /* writes empty path error to standarderrorderrderr */
		write(STDERR_FILENO, ERR_PATH, _strlen(ERR_PATH));
		break;

	default:
		return;
	}
}
