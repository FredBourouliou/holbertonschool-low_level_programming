#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_strings - a function that prints strings
 * @separator: a character
 * @n: an integer
 * Return: 0
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
va_list args;
unsigned int i;
va_start(args, n);
for (i = 0; i < n; i++)
{
const char *str = va_arg(args, const char *);
if (str == NULL)
printf("(nil)");
else
printf("%s", str);
if (i < n - 1 && separator != NULL)
printf("%s", separator);
}
printf("\n");
va_end(args);
}
