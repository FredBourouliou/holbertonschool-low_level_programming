#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Generates a random valid password for the 101-crackme program
 * Return: Always 0 (Success)
 */
int main(void)
{
int sum = 0;
char password[100];
int i = 0;
srand(time(0));
while (sum < 2772 - 126)
{
int rand_char = rand() % 94 + 33;
password[i++] = rand_char;
sum += rand_char;
}
password[i++] = 2772 - sum;
password[i] = '\0';
printf("%s\n", password);
return (0);
}
