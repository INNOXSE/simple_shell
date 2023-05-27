#include "main.h"

/**
 * _getline - Reads a line of input from the user.
 *
 * Description: This function reads a line of input from the user using the
 * `getline` function. It displays a prompt before reading the input. If an
 * error occurs or the user enters an EOF character, the function frees the
 * input buffer, exits the program with the specified status, and returns -1.
 *
 * @input: Pointer to the buffer where the input line will be stored.
 * @number_of_malloc_bytes_allocated: Pointer to the number of bytes allocated
 *                                     for the input buffer.
 * @status: The exit status to use if an error occurs or EOF is encountered.
 *
 * Return: The number of characters read (excluding the null terminator) on
 *         success, or -1 on failure.
 */
ssize_t _getline(char **input, size_t
		*number_of_malloc_bytes_allocated, int status)
{
	ssize_t number_of_characters_read;

	prompt();
	number_of_characters_read =
		getline(input, number_of_malloc_bytes_allocated, stdin);
	if (number_of_characters_read == -1)
	{
		free(*input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (number_of_characters_read);
}
