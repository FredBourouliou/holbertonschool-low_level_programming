#include <stdio.h>
#include <ctype.h>

/**
* main - Entry point
* Return: Always 0 (Success)
*/
int main(void)
{
char alphabet;
for (alphabet = 'a'; alphabet <= 'z' ; alphabet++)
putchar(alphabet);
putchar(toupper(alphabet));
putchar('\n');
return (0);
}
