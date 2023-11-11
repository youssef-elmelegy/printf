#include "main.h"

/**
 * _printf - function that print s c % i d
 * @format: the format
 * Return: count of printed bytes
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			switch (*format)
			{
				case 'c': {
						char c = va_arg(args, char *);

						_putchar(c);
						count++;
						break;
					}
				case 's': {
						char *str = va_arg(args, char *);

						while (*str != '\0')
						{
							_putchar(*str);
							str++;
							count++;
						}
						break;
					}
				case '%':
					{
						_putchar('%');
						count++;
						break;
					}
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						int temp = 1;

						if (num < 0) 
						{
							_putchar('-');
							count++;
							num = -num;
						}

						while (num / temp >= 10)
						{
							 temp *= 10;
						}
						while (temp != 0)
						{
							_putchar((num / temp) + '0');
							count++;
							num %= temp;
							temp /= 10;
						}
						break;
					}
				default:
					break;
			}
		} else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}
