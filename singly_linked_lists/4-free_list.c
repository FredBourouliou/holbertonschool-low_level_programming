#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the head of the list
 */
void free_list(list_t *head)
{
    list_t *current;

    while (head != NULL)
    {
        /* Sauvegarder le prochain nœud */
        current = head->next;
        /* Libérer la chaîne allouée */
        free(head->str);
        /* Libérer le nœud */
        free(head);
        /* Passer au nœud suivant */
        head = current;
    }
}
