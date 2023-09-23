#ifndef MAIN_HEADER
#define MAIN_HEADER

/***LIBRARYS***/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/****FUNCTIONS****/

int _printf(const char *format, ...);
int all_specifier(const char *format, va_list ap);
int specifiers_1(const char *format, va_list ap);
int specifier_2(const char *format, va_list ap);
int print_character(va_list ap);
int my_putchar(char c);
int print_string(va_list ap);
int print_decint(va_list arg);
int print_binary(va_list ap);
int print_unsign(va_list ap);
int print_octal(va_list ap);
int print_hexlower(va_list ap);
int print_hexupper(va_list ap);
/********BUFFER HANDLING**********/
/**MACROS***/


#endif
