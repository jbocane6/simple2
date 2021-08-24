#include "holberton.h"

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

int _strlen(char *s)
{
	return (*s != '\0' ? 1 + _strlen(s + 1) : 0);
}

int _atoi(char *s)
{
	int numero = 0;

	for (int i = 0; s[i]; i++)
		numero = (numero * 10) + (s[i] - '0');
	return (numero);
}
