#include "holberton.h"

/**
 * arrayFree - free memory of the array
 * @array: double pointer to array char variable
 */
void arrayFree(char **array)
{
	if (array && *array)
	{
		arrayFree(array + 1);
		free(*array);
	}
}

/**
 * freestr - free memory of strings data
 * @strfather: double pointer to string char variable
 * @strReceived: pointer to string char variable
 */
void freestr(char **strfather, char *strReceived)
{
	arrayFree(strfather);
	free(strfather);
	free(strReceived);
}
