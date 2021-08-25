#include "holberton.h"

/**
 * _strcat - concatenates two strings
 * @dest: chain initial
 * @src: chain to join with *dest
 * Return: return pointer a dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0, sizeDest = 0;
	char *concat = dest;

	while (dest[i] != '\0')
	{
		sizeDest++;
		i++;
	}
	while (src[j] != '\0')
	{
		dest[sizeDest + j] = src[j];
		j++;
	}
	dest[sizeDest + j] = src[j];

	return (concat);
}

/**
 * *concatPlusPlus - combine received path with the command to use
 * @nVariables: int variable amount of paremeters received
 * Return: return new string or NULL if fails
 */
char *concatPlusPlus(int nVariables, ...)
{
	int i = 0;
	char buffer[1024], *string = NULL;
	va_list list;

	va_start(list, nVariables);

	for (i = 0; nVariables > 0; nVariables--)
		for (string = va_arg(list, char *); *string; i++)
			buffer[i] = *string++;
	buffer[i] = '\0';
	va_end(list);
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	while (i >= 0)
		string[i] = buffer[i], i--;

	return (string);
}

/**
 * *combine - complete the process of concat path with command and free
 * memory used for this process
 * @command: pointer to char variable that contains the command
 * @splitPath: double pointer to string of paths
 * Return: return command received or complete path
 */
char *combine(char *command, char **splitPath)
{
	int i = 0;
	struct stat st;
	char *commandCombine;

	while (i < _strstrlen(splitPath) - 1)
	{
		commandCombine = concatPlusPlus(3, splitPath[i], "/", command);
		if (!commandCombine)
			return (command);
		if (stat(commandCombine, &st) == 0)
		{
			arrayFree(splitPath);
			free(splitPath);
			free(command);
			return (commandCombine);
		}
		free(commandCombine);
		i++;
	}
	arrayFree(splitPath);
	free(splitPath);
	return (command);
}
