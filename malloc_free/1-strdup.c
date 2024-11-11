#include "main.h"
#include <stdlib.h>
/**
 * *_strdup - Returns a pointer to a newly allocated space in memory
 * @str: The string to duplicate.
 * Return: A pointer to the duplicated string, or NULL
 */
char *_strdup(char *str)
{
char *copy;
int i, length = 0;
if (str == NULL)
return (NULL);
while (str[length])
length++;
copy = malloc((length + 1) * sizeof(char));
if (copy == NULL)
return (NULL);
for (i = 0; i <= length; i++)
copy[i] = str[i];
return (copy);
}
