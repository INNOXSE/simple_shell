#include "lists.h"

/**
 * free_listtoken - Frees a listtoken_t list.
 *
 * Description: This function frees a listtoken_t list by iterating through
 * the nodes and freeing the memory allocated for each node and its token.
 *
 * @head: Pointer to a pointer that points to the first node.
 *
 * Return: void
 */
void free_listtoken(listtoken_t **head)
{
	listtoken_t *node;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		node = *head;
		*head = node->next;
		free(node->token);
		free(node);
	}

	*head = NULL;
}
