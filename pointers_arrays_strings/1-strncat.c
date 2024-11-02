#include "main.h"
/**
 * *_strncat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of bytes
 * Return: A pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
int i = 0, j = 0;
while (dest[i] != '\0')
{
i++;
}
while (j < n && src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}
dest[i] = '\0';
return (dest);
}
