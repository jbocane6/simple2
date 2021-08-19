#include <stdio.h>
#include <stdlib.h>

extern char **environ;


char *getVariableForEnviron(char *variableName)
{
    int i = 0, j = 0;
    char *result;

    for (i = 0; environ[i]; i++)
    {
        for (j = 0; environ[i][j] == variableName[j]; j++)
        {
        }
        if (variableName[j] == '\0' && environ[i][j] == '=')
        {
        return (&environ[i][j + 1]);
        }
    }

 return NULL;
}

/**
 * main - main function
 * @argc: Amount of arguments received
 * @argv: Pointer to an array to char received 
 * Return: 0
*/

int main(void)
{
    char *pathValue = getVariableForEnviron("PATH");
    printf("%s\n",pathValue);
    return (0);
}