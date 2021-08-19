#include "holberton.h"

void statPath(char **strfather)
{
    struct stat st;
    if (stat(strfather[0], &st) == 0)
            callchildren(strfather);
    else
        exit(0);
}