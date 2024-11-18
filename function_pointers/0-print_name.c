#include "function_pointers.h"
/**
 * print_name - prints a name
 * @name: the name to print
 * @f: a pointer to a function that prints a name
 */
void print_name(char *name, void (*f)(char *))
{
if (f && name)
f(name);
return;
}
