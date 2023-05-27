#include "lists.h"

/**
 * listtoken_len - Returns the number of elements in a linked listtoken_t list.
 *
 * Description: This function counts the number of elements in a linked list
 * of type listtoken_t. It traverses the list starting from the head node and
 * increments a counter for each node encountered until the end of the list.
 *
 * @head: Pointer to the first node of the list.
 *
 * Return: The number of elements in the linked list.
 */
size_t listtoken_len(const listtoken_t *head)
{
	size_t count = 0;
	const listtoken_t *current;

	if (head == NULL)
		return (0);

	current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
