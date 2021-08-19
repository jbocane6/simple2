#include "holberton.h"

static int FLAG = 0;

int count(char *test)
{
	int i = 0, cfather = 0;

	while (test[i])
	{
		if (!include_char(DELIM, test[i]))
		{
			cfather += count_words(DELIM, test + i);
			break;
		}
		else
			i++;
	}
	return (cfather);
}

void fill(char *test, char **strfather, int *l)
{
	int i = 0;
	char *strCopy = NULL;

	while (test[i])
	{
		if (!include_char(DELIM, test[i]))
		{
			strCopy = cp_until(DELIM, test + i);
			grid(strfather, strCopy, l);
			i += count_until(DELIM, test + i);
		}
		else
			i++;
	}
}

void callchildren(char **strfather)
{
	if (execve(strfather[0], strfather, NULL) == -1)
		perror("Error");
	exit(0);
}

void changeFlag(void)
{
	FLAG = 1;
}

int main(void)
{
	int cfather, l = 0;
	char *test, **strfather = NULL;
	pid_t child, father = getpid();

	while (FLAG == 0)
	{
		child = fork();
		if (child == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child == 0)
		{
			test = readline();
			if (!test)
				dprintf(err, "ERROR"), exit(99);
			
			cfather = count(test);

			strfather = malloc(sizeof(char *) * cfather + 1);
			if (!strfather)
				dprintf(err, "ERROR malloc"), exit(100);

			fill(test, strfather, &l);
			strfather[l] = NULL;

			if (strcmp(strfather[0], "exit") == 0)
			{
				changeFlag();
				kill(father, SIGKILL);
				exit(100);
			}
				
			statPath(strfather);
		}
		else
		{
			wait(0);
			printf("child exited with status of %d\n", WEXITSTATUS(0));
		}
	}
	return (0);
}
