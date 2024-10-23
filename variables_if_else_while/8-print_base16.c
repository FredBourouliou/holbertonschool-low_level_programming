#include <stdio.h>
/**
* main - Entry point
* Return: Always 0 (Success)
*/
int main(void)
{
int i;
char alphabet;
for (i = 0; i <= 9; i++)
printf("%d", i);
for (alphabet = 'a'; alphabet <= 'f' ; alphabet++)
putchar(alphabet);
return (0);
}
