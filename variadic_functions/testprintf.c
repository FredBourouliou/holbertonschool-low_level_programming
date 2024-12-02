#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_all - Prints anything based on the format.
 * @format: A list of types of arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
va_list args;
int i = 0;
char *str, *sep = "";
va_start(args, format);
while (format && format[i])
{
if(format[i] == 'c')
{
printf("%s%c", sep, va_arg(args, int));
}
}
return();
}
