#include "main.h"

/**
 * print_char - Print character to stdout
 * @buffer: Buffer
 * @list: Args
 *
 * Return: -1 or nonezero
 */

int print_char(char *buffer, va_list list)
{
	char c = va_arg(list, int);

	if (!buffer)
		return (-1);

	return (handle_write_char(buffer, c));
}


/**
 * print_str - Handle printing of characters
 * @buffer: Buffer
 * @list: Args
 *
 * Return: -1 or nonezero
 */

int print_str(char *buffer, va_list list)
{
	int i, printed = 0;
	char *str = va_arg(list, char *);

	if (!buffer)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
		printed += handle_write_char(buffer, str[i]);

	return (printed);
}


/**
 * print_percent - Handle printing percent
 * @buffer: Buffer
 * @list: Args
 *
 * Return: -1 or nenezero
 */

int print_percent(char *buffer, va_list list)
{
	UNUSED(list);

	if (!buffer)
		return (-1);

	return (handle_write_char(buffer, '%'));
}

/**
 * print_integer - Handle Printing of integer
 * @buffer: Buffer
 * @list: Variable arguments
 *
 * Return: -1 or nonezero value
 */

int print_integer(char *buffer, va_list list)
{
	int num, i = 1;

	if (!buffer)
		return (-1);
	
	num = va_arg(list, int);

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	

	return (write(1, &buffer[1], i));
}

/**
 * print_binary - Print binary number
 * @buffer: Buffer storage
 * @list: Argument
 *
 * Return: -1 or nonezero
 */

int print_binary(char *buffer, va_list list)
{
	unsigned int num;
	int length = BUFFER - 1;
	
	if (!buffer)
		return (-1);
	
	buffer[length--] = '\0';	
	num = va_arg(list, unsigned int);

	while(num > 0)
	{
		buffer[length--] = (num & 1) + '0';
		num = num >> 1;
	}
	
	length++;
	
	return (write(1, &buffer[length], BUFFER - length - 1));
}
