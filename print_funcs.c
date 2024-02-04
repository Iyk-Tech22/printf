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
	if (!buffer)
		return (-1);

	return (handle_write_char(buffer, '%'));
}
