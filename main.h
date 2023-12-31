#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

/* _printf.c */
int _printf(const char *format, ...);

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}

/* print_sip.c file */
int print_char(va_list args, int count);
int print_string(va_list args, int count);
int print_number(va_list args, int count);

/* _spacifiers.c file*/
int all_spacifiers(const char *format, va_list args, int count);
int print_HEX(va_list args, int count);
int print_hex(va_list args, int count);
int print_octal(va_list args, int count);
int print_unsign(va_list args, int count);

int _putchar(char c);

/* print_binary.c */
int print_binary(va_list args, int count);



#endif
