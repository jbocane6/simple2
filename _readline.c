#include "holberton.h"

/**
 * ctrap - Rewrite prompt when ctrl + c is used
 * @sig: int to indicate next data
 * Return: void
 */
void ctrap(int sig)
{
	if (isatty(in))
		write(out, "\n$ ", sig + 2);
}

/**
 * readline - read and check characters of string to assign
 * dynamic memory
 * @strReceived: double pointer type char that contents the strings
 * Return: return string variable or NULL if it fails
 */

char *readline(char *strReceived)
{
	(void)signal(SIGINT, ctrap);

	strReceived = malloc(sizeof(char) * 1024);
	strReceived[0] = '\0';

	if (isatty(in))
		write(out, "$ ", 2);

	scanf("%[^'\n']s", strReceived);
  	while ((getchar()) != '\n');

	if (strReceived[0] == '\0')
	{
		free(strReceived);
		return (NULL);
	}

	return (strReceived); 
}