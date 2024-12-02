#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to the head of the list
 * @str: string to be duplicated and added to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *temp;

	if (head == NULL || str == NULL)
		return (NULL);

	/* Allouer de la mémoire pour le nouveau nœud */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* Dupliquer la chaîne avec strdup */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Initialiser les autres champs du nouveau nœud */
	new_node->len = strlen(str);
	new_node->next = NULL;

	/* Si la liste est vide, le nouveau nœud devient la tête */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* Parcourir jusqu'au dernier nœud */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	/* Lier le dernier nœud au nouveau nœud */
	temp->next = new_node;

	return (new_node);
}
