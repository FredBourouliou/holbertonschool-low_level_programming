#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the minimum number of coins to make change
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 if successful, 1 if error
 */
int main(int argc, char *argv[])
{
    int cents, coins = 0;
    
    if (argc != 2)
    {
        printf("Error\n");
        return (1);
    }
    
    cents = atoi(argv[1]);
    
    if (cents < 0)
    {
        printf("0\n");
        return (0);
    }
    
    while (cents > 0)
    {
        if (cents >= 25)
            cents -= 25;
        else if (cents >= 10)
            cents -= 10;
        else if (cents >= 5)
            cents -= 5;
        else if (cents >= 2)
            cents -= 2;
        else
            cents -= 1;
        coins++;
    }
    
    printf("%d\n", coins);
    return (0);
}
