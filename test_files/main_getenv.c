#include "shell.h"

/**
 * main env file - prints the environment
 *
 * Return: Always 0. on all successes
 */
int main(void)
{
	printf("Value: %s\n", _getenv("HOME"));
	printf("Value: %s\n", _getenv("LOCATION"));
	printf("Value: %s\n", _getenv("DEFAULT_LOCATION"));
	printf("Value: %s\n", _getenv("SHELL H"));
	printf("Value: %s\n", _getenv("LS_COLS"));

	return (0);
}
