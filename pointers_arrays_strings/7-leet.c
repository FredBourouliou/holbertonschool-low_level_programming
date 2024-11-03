#include "main.h"
/**
 * leet - Encodes a string into 1337 (leet)
 * @str: The string to encode
 * Return: A pointer to the resulting string with encoded characters
 */
char *leet(char *str)
{
int i, j;
char letters[] = "aAeEoOtTlL";
char leet_chars[] = "430071";
for (i = 0; str[i] != '\0'; i++)
{
for (j = 0; letters[j] != '\0'; j++)
{
if (str[i] == letters[j])
{
str[i] = leet_chars[j / 2];
break;
}
}
}
return (str);
}
