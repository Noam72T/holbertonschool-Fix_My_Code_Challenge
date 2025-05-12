#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given index
 *                            in a doubly linked list
 * @head: Pointer to the pointer to the head of the list
 * @index: Index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;
	i = 0;

	/* Traverse to the node at index */
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	/* If it's the head node */
	if (current->prev == NULL)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		current->prev->next = current->next;
		if (current->next != NULL)
			current->next->prev = current->prev;
	}

	free(current);
	return (1);
}
