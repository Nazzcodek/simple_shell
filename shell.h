#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_WORD_COUNT 100

extern char **environ;

int main(void);
/* int main(int argc, char *argv[], char **env);*/
bool is_delimiter(char c, char *delimiters);
bool _check_file(char *filepath, struct stat *statbuf);
char **split_string(char *str, char *seperator, int *word_count);
int _execute(char *arguments, struct stat *statbuf, char **envp);
void set_zeros(unsigned int *arr, size_t size);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *s);
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
char *find_path(char *command);
char *create_file_path(char *path_token, char *command);
char *iterate_paths(char *full_path, char *command);
void free_string_array(char **array, int size);
char *_strchr(const char* str, int c);
unsigned int words_count(char *str, char *separators, unsigned int *arr);
unsigned int shift_string(char **str, char *separators);
char *_getenv(const char *name);
void _env(void);

#endif /* __SHELL_H__*/
