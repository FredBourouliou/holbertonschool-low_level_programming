#include <stdlib.h>
#include "3-calc.h"
#include <stdio.h>
#include <string.h>
#include <stderr>

typedef struct {
    char *op;
    int (*func)(int, int);
} ops_t;
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int op_mod(int a, int b) { return a % b;}
int divide(int a, int b) {
    if (b == 0)
    {
        fprintf(stderr, "divided by zero\n");
    }    return a / b;
}ops_t ops [] = {
    {"+", add},
    {"-", sub},
    {"*", mul},
    {"/", divide},
    {NULL, NULL}
};int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        fprintf(stderr, "usage: <num1> <operateur> <num2>%s\n", argv[0]);
        return EXIT_FAILURE;
    }    int (*opera)(int, int) = NULL;    int num1 = atoi(argv[1]);
    char *operateur = argv[2];
    int num2 = atoi(argv[3]);    for (int i = 0; ops[i].op != NULL; i++)
    {
        if (strcmp(ops[i].op, operateur) == 0)
        {
            opera = ops[i].func;
            break;
        }        if (opera == NULL)
        {
            fprintf(stderr, "operateur inconnu%s\n", argv[2]);
        }
    }    int result = opera(num1, num2);    printf("result: %d\n", result);    return EXIT_SUCCESS;}
