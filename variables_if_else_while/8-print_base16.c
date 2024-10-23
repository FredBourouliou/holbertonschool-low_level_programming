#include <stdio.h>
/**
* main - Entry point
* Return: Always 0 (Success)
*/
int main(void)
{
int n;
char alphabet;
for (n = 0; n <= 9; n++)
putchar('0' + n);
for (alphabet = 'a'; alphabet <= 'f' ; alphabet++)
putchar(alphabet);
return (0);
}
