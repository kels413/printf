#ifndef MAIN_HEADER
#define MAIN_HEADER

/***LIBRARYS***/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/****FUNCTIONS****/

int _printf(const char *format, ...);
int print_character(va_list ap);
int my_putchar(char c);
int print_string(va_list ap);
int print_decint(va_list arg);
int specifier1(const char *format, va_list ap);

/********BUFFER HANDLING**********/
/**MACROS***/


#endif
