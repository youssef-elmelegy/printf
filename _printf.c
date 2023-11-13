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

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count = all_spacifiers(format, args, count);
		}
		else
			count += _putchar(*format);
		format++;
	}

	va_end(args);
	return (count);
}
