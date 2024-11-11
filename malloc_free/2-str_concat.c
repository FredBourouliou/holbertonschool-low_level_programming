#include "main.h"
#include <stdlib.h>
/**
 * str_concat - Concatenates two strings
 * @s1: The first string.
 * @s2: The second string.
 * Return: A pointer to the newly allocated space
 */
char *str_concat(char *s1, char *s2)
{
char *concat_str;
int len1 = 0, len2 = 0, i, j;
while (s1 && s1[len1])
len1++;
while (s2 && s2[len2])
len2++;
concat_str = malloc((len1 + len2 + 1) * sizeof(char));
if (concat_str == NULL)
return (NULL);
for (i = 0; i < len1; i++)
concat_str[i] = s1[i];
for (j = 0; j < len2; j++, i++)
concat_str[i] = s2[j];
concat_str[i] = '\0';
return (concat_str);
}
