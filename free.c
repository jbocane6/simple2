#include "holberton.h"

void arrayFree(char **array)
{
	if (array && *array)
	{
		arrayFree(array + 1);
		free(*array);
		/*return;*/
	}
}

void freestr(char **strfather, char *strReceived)
{
	arrayFree(strfather);
	free(strfather);
	free(strReceived);
}
