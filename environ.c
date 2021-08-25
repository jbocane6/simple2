#include "holberton.h"

/**
 * validateMainFunctions - verifies if the command is built-in
 * @strf: double pointer to string char variable tokenized
 * @strRecd: pointer to char variable string before tokenized
 * @chars: amount of characters received in the getline
 * @loo: number of interations made by user
 * Return: return 1 or call to statPath
 */
int validateMainFunctions(char **strf, char *strRecd, int chars, int loo)
{
	int i = chars;

	if (_strcmp(strf[0], "exit") == 0)
	{
		if (i > 1)
		{
			i = _atoi(strf[1]);
			freestr(strf, strRecd);
			exit(i); /*cambiar por 0 y probar*/
		}
		else
		{
			freestr(strf, strRecd);
			exit(0);
		}
	}
	if (_strcmp(strf[0], "cd") == 0)
	{
		chdir(strf[1]);
		return (0);
	}
	if (_strcmp(strf[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(out, environ[i], _strlen(environ[i]));
			write(out, "\n", 1);
		}
		return (0);
	}
	return (statPath(strf, loo));
}

/**
 * *get_environ - obtain path and include environ
 * @pathName: pointer to char variable with "PATH"
 * Return: return path found in environ or NULL
 */
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
