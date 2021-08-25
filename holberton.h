#ifndef _HEADER_SHELL_
#define _HEADER_SHELL_

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdarg.h>

#define TEST_TOK
#define SIZE_SLASH (1)
#define SIZE_NULL (1)
#define out STDOUT_FILENO
#define in STDIN_FILENO
#define DELIM " \""

extern char **environ;

char *readline(char *strReceived);
/* _strlen - count the characters of string and return size */
int _strlen(char *s);
/* _strcat - concatenates two strings */
char *_strcat(char *dest, char *src);
/* *concatPlusPlus - combine received path with the command to use */
char *concatPlusPlus(int nVariables, ...);
/* include_char - search for position of character that contains delimiter */
int include_char(char *str, char character);
/* count_until - count characters until delimiter */
int count_until(char *strUntil, char *str);
/*cp_until - create and array with characters that exist before delimiter*/
char *cp_until(char *strUntil, char *strToCopy);
/* count_words - count amount of words are separeted by the deilimiters */
int count_words(char *strDelim, char *str);
/* **_strtok - create an array of strings tokenized */
char **_strtok(char *str, char *delim);
/* statPath - recieve the command with or without i'ts path and */
int statPath(char **strfather, int loops);
/* callExe - fork a child to avoid execve to terminate main process */
int callExe(char **strfather);
/* *get_environ - obtain path and include environ  */
char *get_environ(char *pathName);
/* *combine - complete the process of concat path with command and free */
char *combine(char *command, char **splitPath);
/* validateMainFunctions - verifies if the command is built-in */
int validateMainFunctions(char **strf, char *strRecd, int chars, int loo);
/* arrayFree - free memory of the array */
void arrayFree(char **array);
/* _atoi - convert the string to number */
int _atoi(char *s);
/* ctrap - Rewrite prompt when ctrl + c is used */
void ctrap(int sig);
/* freestr - free memory of strings data */
void freestr(char **strfather, char *strReceived);
/* *move_last_until - receive string and return the command that */
char *move_last_until(char *string, char last);
/*print_number - called to main()*/
void print_number(int n);
/*_strcmp - compares 2 strings and say if are equals*/
int _strcmp(char *str1, char *str2);
int _strstrlen(char **s);

#endif
