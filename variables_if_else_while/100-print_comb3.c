#include <stdio.h>
#include <unistd.h>
/**
 * main - Prints all possible different combinations of two digits
 * Return: Always 0 (Success)
 */
int main(void)
{
int first;
int second;

first = 0;
while (first <= 8)
{
second = first + 1;
while (second <= 9)
{
putchar(first + '0');
putchar(second + '0');
if (first != 8 || second != 9)
{
putchar(',');
putchar(' ');
}
second++;
}
first++;
}
putchar('\n');
return (0);
}