#include "holberton.h"

extern char **environ;

int validateMainFunctions(char **strfather, char *strReceived, int character)
{
	int i = character;

	if (strcmp(strfather[0], "exit") == 0)
	{
		if (i > 1)
		{
			i = _atoi(strfather[1]);
			freestr(strfather, strReceived);
			exit(i);
		}
		else
		{
			freestr(strfather, strReceived);
			exit(0);
		}
	}
	if (strcmp(strfather[0], "cd") == 0)
	{
		chdir(strfather[1]);
		return (1); /*no es exit?*/
	}
	if (strcmp(strfather[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(out, environ[i], _strlen(environ[i]));
			write(out, "\n", 1);
		}
		return (1); /*no es exit?*/
	}
	return (statPath(strfather));
}

char *get_environ(char *pathName)
{
	int i = 0, j = 0;

	for (; environ[i]; i++)
	{
		for (; pathName[j]; j++)
		{
			if (environ[i][j] != pathName[j])
				break;
		}
		if (pathName[j] == '\0' && environ[i][j] == '=')
			return (&environ[i][j + 1]);
	}
	return (NULL);
}
