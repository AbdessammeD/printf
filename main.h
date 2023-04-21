#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

struct op
{
	char *op;
	int (*f)(va_list);
};
typedef struct op op;
int handle_char(va_list args);
int handle_numbers(va_list args);
int handle_string(va_list args);
int handle_binary(va_list args);
int print_binary(unsigned int binary);
int print_number(int integer);
int _printf(const char *format, ...);

#endif
