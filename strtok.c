#include "holberton.h"

/**
 * include_char - search for position of character that
 * contains delimiter
 * @str: pointer to a char variable
 * @character: char variable that contains delimiter
 * Return: 0 if is NULL or 1 if found character
 */
int include_char(char *str, char character)
{
	if (!str || !*str)
		return (0);
	if (*str == character)
		return (1);
	return (include_char(str + 1, character));
}

/**
 * count_until - count characters until delimiter
 * @strUntil: pointer to a char variable that contains delimiter
 * @str: pointer to char variable that count characters
 * Return: return amount of characters or 0 if fails
 */
int count_until(char *strUntil, char *str)
{
	if (!strUntil || !*strUntil || !str || !*str)
		return (0);
	if (!include_char(strUntil, *str))
		return (1 + count_until(strUntil, str + 1));
	return (0);
}

/**
 * cp_until - create and array with characters that exist before
 * delimiter
 * @strUntil: pointer to a char variable that contains delimiter
 * @strToCopy: pointer to char variable that count characters
 * Return: return new string or NULL if fails
 */
char *cp_until(char *strUntil, char *strToCopy)
{
	int count = count_until(strUntil, strToCopy), i = 0;
	char *newStr = malloc(sizeof(char) * count + 1);

	if (!newStr)
		return (NULL);

	for (i = 0; i < count; i++)
		newStr[i] = strToCopy[i];
	newStr[i] = '\0';
	return (newStr);
}

/**
 * count_words - count amount of words are separeted by the deilimiters
 * @strDelim: pointer to a char variable that contains delimiter
 * @str: pointer to char variable that count characters
 * Return: return amount of words or 0 if fails
 */
int count_words(char *strDelim, char *str)
{
	if (!str || !*str || !strDelim || !*strDelim)
		return (0);
	if (!include_char(strDelim, *str))
	{
		int sizeWorld = count_until(strDelim, str);

		return (1 + count_words(strDelim, str + sizeWorld));
	}
	return (count_words(strDelim, str + 1));
}

/**
 * **_strtok - create an array of strings tokenized
 * @str: pointer to char variable that count characters
 * @delim: pointer to a char variable that contains delimiter
 * Return: return array of strings or 0 if fails
 */
char **_strtok(char *str, char *delim)
{
	char **arrayWords = NULL;
	int indexWords = 0, sizeWords = 0, i = 0;

	if (!str || !delim)
		return (NULL);
	sizeWords = count_words(delim, str);
	arrayWords = malloc(sizeof(char *) * (sizeWords + 1));
	if (!arrayWords)
		dprintf(out, "ERROR malloc 1"), exit(100);

	while (str[i])
	{
		if (!include_char(delim, str[i]))
		{
			arrayWords[indexWords] = cp_until(delim, str + i);
			i += count_until(delim, str + i);
			indexWords++;
		}
		else
			i++;
	}
	arrayWords[indexWords] = NULL;
	return (arrayWords);
}
