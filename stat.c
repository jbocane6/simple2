#include "holberton.h"

int statPath(char **strfather)
{
	struct stat st;
	/* validate if deault command is absolute path */
	/* example: strfather[0] = /bin/ls */
	if (stat(strfather[0], &st) == 0)
	{
		return (callExe(strfather));
	}
	else
	{
		strfather[0] = combine(strfather[0], _strtok(get_environ("PATH"), ":"));
		if (strfather[0])
			return (statPath(strfather));
	}
	return (1);
}

int callExe(char **strfather)
{
	char stringDir[1024];
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("Error:");
		return (0);
	}
	if (child == 0)
	{
		stringDir[0] = '\0';
		_strcat(stringDir, strfather[0]);
		strfather[0] = move_last_until(strfather[0], '/');
		if (execve(stringDir, strfather, NULL) == -1)
			perror("Error");
		exit(0);
	}
	else
		wait(0);

	return (1);
}