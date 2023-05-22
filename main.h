#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

int _putchar(char c);
void execute_command(char* args[], char *argv[]);
void print_prompt(const char* prompt);
int check_mode();
void interactive_mode(char *argv[]);
void non_interactive_mode(char *argv[]);


char *_strcat(char *s1, char *s2);
char *_strchr(char *s, char c);
size_t _strcspn(const char *str, const char *reject);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
