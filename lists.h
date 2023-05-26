#ifndef LISTS_H_
#define LISTS_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
* struct listtoken_s - Structure for a singly linked list node
* @token: Pointer to a character string (token)
* @token_length: Length of the token
* @next: Pointer to the next node in the linked list
* Description: This structure represents a node in a singly linked list.
* It contains a token (character string), its length, and a reference to the
* next node in the list.
*/
typedef struct listtoken_s
{
	char *token;
	int token_length;
	struct listtoken_s *next;
} listtoken_t;

size_t print_listtoken(const listtoken_t *head);
size_t listtoken_len(const listtoken_t *head);
listtoken_t *add_nodetoken_end(listtoken_t **head, char *token);
void free_listtoken(listtoken_t **head);

#endif
