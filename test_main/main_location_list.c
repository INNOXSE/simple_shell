#include "shell.h"

/**
 * main - Puts the dirs in LOCATION into a linked list using location_list.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *location;
	list_s *list = NULL;
	list_s *current;

	location = _getenv("LOCATION");

	list = locationlist(location, list);

	current = list;

	while (current->next != NULL)
	{
		printf("%s\n", current->value);
		current = current->next;
	}

	free_all(NULL, NULL, NULL, NULL, 0);

	return (0);
}
