#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int my_strlen(char *s);
int print_binary(unsigned int binary);
int print_number(int integer);
int print(char c, va_list args);
int _printf(const char *format, ...);

#endif
