#include "holberton.h"

/**
 * *move_last_until - receive string and return the command that
 * be in the last position of the path
 * @string: variable type char that contains the path
 * @last: variable type char to indicate end of path to extract
 * the command
 * Return: return NULL if string is NULL, if succeed return name
 * of command
 */
char *move_last_until(char *string, char last)
{
	char *result = NULL;

	if (!string || !*string)
		return (NULL);
	result = move_last_until(string + 1, last);
	if (result != NULL)
		return (result);
	if (*string == last)
		return (string + 1);
	return (NULL);
}

/**
 * _strlen - count the characters of string and return size
 * @s: pointer to string char variable
 * Return: return size of s of 0 if it is void
 */
int _strlen(char *s)
{
	return (*s != '\0' ? 1 + _strlen(s + 1) : 0);
}

/**
 * _atoi - convert the string to number
 * @s: pointer to string char variable
 * Return: return number
 */
int _atoi(char *s)
{
	int numero = 0, i;

	for (i = 0; s[i]; i++)
		numero = (numero * 10) + (s[i] - '0');
	return (numero);
}

/**
 * _strcmp - compares 2 strings and say if are equals
 * @str1: pointer to string char variable
 * @str2: pointer to string char variable
 * Return: 0 if are equal, 1 if are different or if it fails
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	if (!str1 || !str2 || _strlen(str1) != _strlen(str2))
		return (1);

	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
			return (1);
	}

	return (0);
}

/**
 * _strstrlen - count the strings of a double pointer to char and return size
 * @s: pointer to double pointer string
 * Return: return size of s of 0 if it is void
 */
int _strstrlen(char **s)
{
	return (*s != NULL ? 1 + _strstrlen(s + 1) : 0);
}
