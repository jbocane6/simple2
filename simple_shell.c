#include "holberton.h"

/**
 * main - receive a line of strings, set in the prompt,
 * line of strings is checked, compares is it built-in or not,
 * check path, validate output in the main function, and display
 * output of command.
 * Return: reference output for end of program.
 */
int main(void)
{
	int flag = 0, character = 0, loops = 1;

	while (flag == 0)
	{
		char *strReceived = NULL, **strfather = NULL;

		strReceived = readline(strReceived);
		if (strReceived)
		{
			character = count_words(DELIM, strReceived);
			strfather = _strtok(strReceived, DELIM);
			flag = validateMainFunctions(strfather, strReceived, character, loops);
		}
		if (flag == 0)
			freestr(strfather, strReceived);
		loops++;
	}
	return (EXIT_SUCCESS);
}
