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
current = head->next;
free(head->str);
free(head);
head = current;
}
}
