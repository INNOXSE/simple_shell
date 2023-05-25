#include "shell.h"

/**
 * main - Prints the dirs in the location environs var using_location_print.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *location = "location";

	locationlist(location, NULL);

	return (0);
}
