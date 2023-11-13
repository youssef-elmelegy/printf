#include "main.h"

/**
 * all_spacifiers - print formats
 * @format: a apacifier format
 * @args: va_list
 * @count: a returned count
 * Return: count
 */

int all_spacifiers(char *format, va_list args, int count)
{
	switch (*format)
	{
		case 'c':
			count = print_char(args, count);
			break;
		case 's':
			count = print_string(args, count);
			break;
		case '%':
			count += _putchar('%');
			break;
		case 'd':
		case 'i':
			count = print_number(args, count);
			break;

		case 'b':
			count = print_octal(args, count);
			break;
		case 'o':
			count = print_octal(args, count);
			break;
		case 'x':
			count = print_hex(args, count);
			break;
		case 'X':
			count = print_HEX(args, count);
			break;
		default:
			count += _putchar('%') + _putchar(*format);
			break;
	}
	return (count);
}

