#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * f1 - Function that generates first character
 * @str: username
 * Return: first character of key
 */
char f1(char *str)
{
    int len = strlen(str);
    int ch;
    int vch = 0;

    for (ch = 0; ch < len; ch++)
        vch += str[ch];
    return ((vch ^ 59) & 63) + 'A';
}

/**
 * f2 - Function that generates second character
 * @str: username
 * Return: second character of key
 */
char f2(char *str)
{
    int len = strlen(str);
    int ch;
    long vch = 1;

    for (ch = 0; ch < len; ch++)
        vch = vch * str[ch];
    return ((vch ^ 79) & 63) + 'A';
}

/**
 * f3 - Function that generates third character
 * @str: username
 * Return: third character of key
 */
char f3(char *str)
{
    int len = strlen(str);
    int ch;
    long vch = str[0];

    for (ch = 0; ch < len; ch++)
        if (str[ch] > vch)
            vch = str[ch];
    srand(vch ^ 0x1234);
    return (rand() & 63) + 'A';
}

/**
 * f4 - Function that generates fourth character
 * @str: username
 * Return: fourth character of key
 */
char f4(char *str)
{
    int len = strlen(str);
    int ch;
    long vch = 0;

    for (ch = 0; ch < len; ch++)
        vch = str[ch] * str[ch] + vch;
    return ((vch ^ 9) & 63) + 'A';
}

/**
 * f5 - Function that generates fifth character
 * @str: username
 * Return: fifth character of key
 */
char f5(char *str)
{
    int len = strlen(str);
    int ch;
    long vch = 0;

    for (ch = 0; ch < len; ch++)
    {
        vch = vch + str[ch];
    }
    return ((vch ^ 0x55) & 63) + 'A';
}

/**
 * f6 - Function that generates sixth character
 * @str: username
 * Return: sixth character of key
 */
char f6(char *str)
{
    int ch;
    long vch = 0;

    for (ch = 0; str[ch]; ch++)
        vch = rand() & 63;
    return (vch + 'A');
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char key[7];
    char *username;

    if (argc != 2)
    {
        printf("Correct usage: ./keygen5 username\n");
        return (1);
    }

    username = argv[1];
    key[0] = f1(username);
    key[1] = f2(username);
    key[2] = f3(username);
    key[3] = f4(username);
    key[4] = f5(username);
    key[5] = f6(username);
    key[6] = '\0';

    printf("%s", key);
    return (0);
}
