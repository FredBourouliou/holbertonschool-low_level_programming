#include "main.h"

/**
 * wildcmp - compares two strings with wildcard support
 * @s1: first string to compare
 * @s2: second string to compare (can contain wildcards)
 *
 * Return: 1 if strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
    /* If we reach end of both strings, they're identical */
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    /* If current characters match or s2 has '?', move to next chars */
    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));

    /* If we find a '*' in s2 */
    if (*s2 == '*')
    {
        /* Two possibilities after '*':
         * 1. '*' matches nothing: skip '*' in s2
         * 2. '*' matches current char in s1: skip char in s1
         */
        return (wildcmp(s1, s2 + 1) || /* Case 1: '*' matches nothing */
                (*s1 != '\0' && wildcmp(s1 + 1, s2))); /* Case 2: '*' matches current char */
    }

    /* If none of the above conditions are met, strings don't match */
    return (0);
} 