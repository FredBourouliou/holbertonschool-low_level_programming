#include "lists.h"

/**
 * print_list - prints all elements of a list_t list
 * @h: pointer to the list to print
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
size_t count = 0;
char *str;
char num_str[20];
int i, len;
while (h != NULL)
{
_putchar('[');
if (h->str == NULL)
{
_putchar('0');
str = "(nil)";
}
else
{
len = 0;
i = h->len;
do {
num_str[len++] = i % 10 + '0';
i /= 10;
} while (i > 0);
for (i = len - 1; i >= 0; i--)
_putchar(num_str[i]);
str = h->str;
}
_putchar(']');
_putchar(' ');
for (i = 0; str[i] != '\0'; i++)
_putchar(str[i]);
_putchar('\n');
h = h->next;
count++;
}
return (count);
}
