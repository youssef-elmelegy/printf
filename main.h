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

/**
 * struct parameters - parameters struct
 *
 * @unsign : flag if unsigned value
 *
 * @plus : on if plus specified
 * @space : on if _flag specified
 * @hashtag : # flag
 * @zero : on if _flag specified
 * @minus : on if _flag specified
 *
 * @width : field width specified
 * @precision : field precision specified
 *
 * @h : on if h_modifier is specified
 * @l : on if l_modifier is specified
*/
typedef struct parameters
{
	unsigned int unsign	: 1;

	unsigned int plus	: 1; /* plus flag (+) */
	unsigned int space	: 1; /* space */
	unsigned int hashtag	: 1; /* # flag */
	unsigned int zero	: 1; /* zero flag */
	unsigned int minus	: 1; /* minus flag */

	unsigned int h	: 1; /* h modifier */
	unsigned int l	: 1; /* l modifier */

	unsigned int width;	/* field width */
	unsigned int precision;
} params;

/**
 * print_char: that print a character
 * print a character: prints a %
 * print_string: ptints a string
 * print_int: prints int
 * print_S: S
 *
 * print_binary: prints unsigned int argument (%b)
 * print_hex: x
 * print_HEX: X
 * print_octal: o
 * print_unsigned: u
 * print_address: p
 *
 * print_rev: prints reversed specifier
 * print_rot13: prints rot13'ed string
*/

/* print_name */
int print_char(va_list ap, params *params);
int print_percent(va_list ap, params *params);
int print_string(va_list ap, params *params);
int print_int(va_list ap, params *params);
int print_S(va_list ap, params *params);

int print_binary(va_list ap, params *params);
int print_hex(va_list ap, params *params);
int print_HEX(va_list ap, params *params);
int print_octal(va_list ap, params *params);

int print_unsigned(va_list ap, params *params);
int print_address(va_list ap, params *params);

int print_rev(va_list ap, params *params);
int print_rot13(va_list ap, params *params);


/* print_sip.c file */
int print_char(va_list args, int count);
int print_string(va_list args, int count);
int print_number(va_list args, int count);

int _putchar(char c);
#endif
