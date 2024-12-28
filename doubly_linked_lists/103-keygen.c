#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int f1(char *str)
{
    unsigned int len = 0;
    unsigned int i;
    unsigned int result = 0;

    len = strlen(str);
    for (i = 0; i < len; i++)
        result += str[i];
    return (result ^ 0x3B);
}

unsigned int f2(char *str)
{
    unsigned int len = 0;
    unsigned int i;
    unsigned int result = 1;

    len = strlen(str);
    for (i = 0; i < len; i++)
        result *= str[i];
    return (result ^ 0x4F);
}

unsigned int f3(char *str)
{
    unsigned int len = 0;
    unsigned int i;
    unsigned int result;
    unsigned char current;

    result = (unsigned int)str[0];
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        current = (unsigned char)str[i];
        if ((unsigned int)current > result)
            result = (unsigned int)current;
    }
    srand(result ^ 0x1337);
    return (rand() & 0x3F);
}

unsigned int f4(char *str)
{
    unsigned int len = 0;
    unsigned int i;
    unsigned int result = 0;

    len = strlen(str);
    for (i = 0; i < len; i++)
        result += str[i] * str[i];
    return (result ^ 0x4F);
}

unsigned int f5(char *str)
{
    unsigned int i;
    unsigned int result = 0;

    for (i = 0; str[i]; i++)
        result += str[i];
    return (result ^ 0x55);
}

int main(int argc, char **argv)
{
    char *username;
    char key[7];
    unsigned int i;

    if (argc != 2)
    {
        printf("Usage: %s username\n", argv[0]);
        return (1);
    }

    username = argv[1];
    key[0] = ((f1(username) ^ 0x3B) & 0x3F) + 'A';
    key[1] = ((f2(username) ^ 0x4F) & 0x3F) + 'A';
    key[2] = ((f3(username)) & 0x3F) + 'A';
    key[3] = ((f4(username) ^ 0x4F) & 0x3F) + 'A';
    key[4] = ((f5(username) ^ 0x55) & 0x3F) + 'A';
    key[5] = 0;

    for (i = 0; username[i]; i++)
        key[5] += username[i];
    key[5] = (key[5] & 0x3F) + 'A';
    key[6] = '\0';

    printf("%s\n", key);
    return (0);
}
