#include "main.h"
/**
 * char *_memcpy(char *dest, char *src, unsigned int n) - function that copies memory area.
 * @dest: memory area
 * @src: constant byte to fill
 * @n: bytes of memory area to fill
 * Return: memory area filled
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int a;
for (a = 0; a < n; a++)
{
dest[a] = *src++;
}
return (dest);
}
