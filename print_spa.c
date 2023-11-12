#include "main.h"

/**
 * print_char - print a character
 * @args: The argument list
 * @count: The count of characters printed
 *
 * Return: Updated count
 */
int print_char(va_list args, int count)
{
	char ch = va_arg(args, int);

	return (count + _putchar(ch));
}

/**
 * print_string - print a string
 * @args: The argument list
 * @count: The count of characters printed
 *
 * Return: Updated count
 */
int print_string(va_list args, int count)
{
	char *str = va_arg(args, char *);

	while (*str)
	{
		count += _putchar(*str++);
	}

	return (count);
}

/**
 * print_number - print a number
 * @args: The argument list
 * @count: The count of characters printed
 *
 * Return: counter
 */
int print_number(va_list args, int count)
{
	int num = va_arg(args, int);
	int temp = 1;

	if (num < 0)
	{
		count += _putchar('-');
		num = -num;
	}

	while (num / temp >= 10)
		temp *= 10;

	while (temp)
	{
		count += _putchar((num / temp) + '0');
		num %= temp;
		temp /= 10;
	}

	return (count);
}
