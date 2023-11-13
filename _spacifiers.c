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
		case 'u':
			count = print_unsign(args, count);
		case 'b':
			count = print_binary(args, count);
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
/**
 * print_unsign - print an unsigned number
 * @args: The argument list
 * @count: The count of characters printed
 * Return: Updated count
 */
int print_unsign(va_list args, int count)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = 1;

	char buffer[BUFFER_SIZE];
	char *ptr = buffer;

	while (num / temp >= 10)
	{
		temp *= 10;
	}

	while (temp)
	{
		*ptr++ = (num / temp) + '0';
		num %= temp;
		temp /= 10;
	}
	count += _write_buffer(buffer, ptr - buffer);
	return (count);
}

/**
 * print_octal - print an octal number
 * @args: The argument list
 * @count: The count of characters printed
 * Return: Updated count
 */
int print_octal(va_list args, int count)
{
	unsigned int num = va_arg(args, unsigned int);
	int temp = 1;

	while (num / temp >= 8)
		temp *= 8;

	while (temp)
	{
		count += _putchar((num / temp) + '0');
		num %= temp;
		temp /= 8;
	}
	return (count);
}

/**
 * print_hex - print a hexadecimal number in lowercase
 * @args: The argument list
 * @count: The count of characters printed
 * Return: Updated count
 */
int print_hex(va_list args, int count)
{
	unsigned int num = va_arg(args, unsigned int);
	int temp = 1;

	while (num / temp >= 16)
		temp *= 16;

	while (temp)
	{
		int digit = num / temp;

		if (digit < 10)
			count += _putchar(digit + '0');
		else
			count += _putchar(digit - 10 + 'a');
		num %= temp;
		temp /= 16;
	}
	return (count);
}

/**
 * print_HEX - print a hexadecimal number in uppercase
 * @args: The argument list
 * @count: The count of characters printed
 * Return: Updated count
 */
int print_HEX(va_list args, int count)
{
	unsigned int num = va_arg(args, unsigned int);
	int temp = 1;

	while (num / temp >= 16)
		temp *= 16;

	while (temp)
	{
		int digit = num / temp;

		if (digit < 10)
			count += _putchar(digit + '0');
		else
			count += _putchar(digit - 10 + 'A');
		num %= temp;
		temp /= 16;
	}
	return (count);
}
