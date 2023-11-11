#include "main.h"

/**
 * _putchar - prints a char
 * @c: a char
 *
 * Return: priented char
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
