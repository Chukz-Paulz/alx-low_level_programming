/*
 * File: 103-keygen.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: { Always 0. }
 */
int main(int argc, char *argv[])
{
    char password[7];
    char *codex;
    int len, i, tmp;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <argument>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    len = strlen(argv[1]);

    if (argv[1] == NULL || len == 0) {
        fprintf(stderr, "Invalid input.\n");
        return (EXIT_FAILURE);
    }

    codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

    tmp = (len ^ 59) & 63;
    password[0] = codex[tmp];

    tmp = 0;
    for (i = 0; i < len; i++)
        tmp += argv[1][i];
    password[1] = codex[(tmp ^ 79) & 63];

    tmp = 1;
    for (i = 0; i < len; i++)
        tmp *= argv[1][i];
    password[2] = codex[(tmp ^ 85) & 63];

    tmp = 0;
    for (i = 0; i < len; i++)
    {
        if (argv[1][i] > tmp)
            tmp = argv[1][i];
    }

    srand((unsigned int)(time(NULL)));
    password[3] = codex[rand() & 63];

    tmp = 0;
    for (i = 0; i < len; i++)
        tmp += (argv[1][i] * argv[1][i]);
    password[4] = codex[(tmp ^ 239) & 63];

    for (i = 0; i < argv[1][0]; i++)
        tmp = rand();
    password[5] = codex[(tmp ^ 229) & 63];

    password[6] = '\0';
    printf("%s", password);
    return (0);
}

