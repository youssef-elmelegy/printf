#include "main.h"

/**
 * print_binary - covert given number to
 * @count : count given
 * @args  : args given
 * Return: number of prints
*/

int print_binary(va_list args, int count)
{
	int *arr;
	int temp = 1, i;
	unsigned int n, a;

	n = va_arg(args, int);
	a = n;
	temp = 0;

	while (a / 2)
	{
		temp++;
		a /= 2;
	}
	temp++;

	arr = (int *)malloc(sizeof(int) * temp);

	if (arr == NULL)
	{
		free(arr);
		return (0);
	}

	for (i = 0; i < temp; i++)
	{
		arr[i] = n % 2;
		n /= 2;
	}

	for (i = temp - 1; i >= 0; i--)
	{
		count += _putchar(arr[i] + '0');
	}

	free(arr);
	return (count);

}
