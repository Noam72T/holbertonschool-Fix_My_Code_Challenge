#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - Test la suppression de nœuds dans une liste doublement chaînée
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	dlistint_t *head = NULL;

	/* Ajout de plusieurs nœuds */
	add_dnodeint_end(&head, 0);
	add_dnodeint_end(&head, 1);
	add_dnodeint_end(&head, 2);
	add_dnodeint_end(&head, 3);
	add_dnodeint_end(&head, 4);
	add_dnodeint_end(&head, 98);
	add_dnodeint_end(&head, 402);
	add_dnodeint_end(&head, 1024);
	print_dlistint(head);
	printf("-----------------\n");
	for (int i = 0; i < 20; i++)
	{
		if (delete_dnodeint_at_index(&head, 0) == -1)
			printf("Échec suppression à l'indice 0\n");
		print_dlistint(head);
		printf("-----------------\n");
	}

	free_dlistint(head);
	return (EXIT_SUCCESS);
}
