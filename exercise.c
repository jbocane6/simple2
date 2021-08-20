#include "holberton.h"

static int FLAG = 0;
extern char **environ;

void changeFlag(void)
{
	FLAG = 1;
}

void validateMainFunctions(char **strfather, pid_t father)
{
	if (strcmp(strfather[0], "exit") == 0)
	{
		changeFlag();
		kill(father, SIGTSTP);
		exit(100);
	}
	statPath(strfather);
}

void callExe(char **strfather)
{
	if (execve(strfather[0], strfather, NULL) == -1)
		perror("Error");
	exit(0);
}

int main(void)
{
	int cfather;
	char *strReceived, **strfather = NULL;
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
			strReceived = readline();
			if (!strReceived)
				exit(99);

			cfather = count_words(DELIM, strReceived);

			strfather = malloc(sizeof(char *) * cfather + 1);
			if (!strfather)
				dprintf(err, "ERROR malloc"), exit(100);

			strfather =_strtok(strReceived, DELIM);
			validateMainFunctions(strfather, father);
		}
		else
			wait(0);
	}
	return (0);
}
