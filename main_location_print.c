#include "shell.h"

/**
 * main - Prints the dirs in the location environs var using_location_print.
 *
 * Return: Always 0.
 */
int main(void)
{
	list_s *list = NULL;
	char *location = "PATH";
	list = locationlist(location, list);
	list_s *current = list;

	while (current != NULL)
	{
		printf("%s\n", current->value);
		current = current->next;
	}

	fr_list(list);
	return (0);
}
