#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * Return: void
 */

void print_all(const char * const format, ...)
{
va_list args;
int i;
va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
switch (format[i])
{
case 'c':
printf("%c", va_arg(args, int));
break;
case 'i':
printf("%d", va_arg(args, int));
break;
case 'f':
printf("%f", va_arg(args, double));
break;
case 's':
const char *str = va_arg(args, const char *);
if (str == NULL)
printf("(nil)");
else
printf("%s", str);
break;
default:
break;
}
if (format[i + 1] != '\0' && format[i] != 's')
printf("%s", (format[i + 1] == ',') ? " " : ", ");
}
va_end(args);
printf("\n");
}