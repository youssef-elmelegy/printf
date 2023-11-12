#include "main.h"

/**
 * _printf - custom printf function
 * @format: The format
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
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
				default:
					count += _putchar('%') + _putchar(*format);
					break;
			}
		}
		else
			count += _putchar(*format);
		format++;
	}

	va_end(args);
	return (count);
}
