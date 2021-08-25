#include "holberton.h"

/**
 * print_number - called to main()
 * @n: number to convert
 * Return: withour return
 */
void print_number(int n)
{
	int n1 = n, i = 0, j, r, arr[sizeof(int) * 8];
	char c;

	if (n != 0)
	{
		while (n != 0)
		{
			r = n % 10;
			arr[i] = r;
			i++;
			n = n / 10;
		}
		for (j = i - 1; j > -1; j--)
		{
			if (n1 < -2147483647)
			{
				c = (arr[j] * -1) + '0';
				write(out, &c, 1);
			}
			else
			{
				c = arr[j] + '0';
				write(out, &c, 1);
			}
		}
	}
}

/**
 * statPath - recieve the command with or without i'ts path and
 * return the call to the function callExe (execve)
 * @strfather: double pointer to string char variable with command tokenized
 * @loops: int variable that contains amount of iterations
 * Return: return call to the function or 1 if it fails
 */
int statPath(char **strfather, int loops)
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
		if (stat(strfather[0], &st) == 0)
		{
			return (callExe(strfather));
		}
		else
		{
			write(out, "sh : ", 5);
			print_number(loops);
			write(out, ": ", 2);
			write(out, strfather[0], _strlen(strfather[0]));
			write(out, ": not found\n", 12);
		}
	}
	return (0);
}

/**
 * callExe - fork a child to avoid execve to terminate main process
 * when run the commands
 * @strfather: double pointer type char type parent to be evaluated
 * Return: if child wasn't created return -1, 1 if  it was succeed
 */
int callExe(char **strfather)
{
	char stringDir[1024];
	int st = 0;
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
	{
		wait(&st);
		return (WEXITSTATUS(st));
	}
	return (0);
}
