#include "main.h"
/**
 * _isalpha - main entry
 * @c: sign of a letter
 * Return: 1 for letter or 0 for anything else
 */
int _isalpha(int c)
{
if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
{
return (1);
}
return (0);
}
