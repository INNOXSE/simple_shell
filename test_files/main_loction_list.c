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
	list_s *currt;

	location = _getenv("location");

	list = location_list(location, list);

	currt = list;

	while (currt->next != NULL)
	{
		printf("%s\n", currt->value);
		currt = currt->next;
	}

	fr_list(list);

	return (0);
}
