#include "main.h"

/**
 * handle_print - Handle print format specifier
 * @fmt: String to print
 * @list: Args to process
 * @fmt_idx: String current index
 *
 * Return: -1 on errort, nonzero success
 */

int handle_print(char *fmt, int *fmt_idx, va_list list, char *buffer)
{
	int i;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percent},
		{'d', print_integer}, {'i', print_integer}, {'b', print_binary},
		{'\0', NULL}
	};

	if (!fmt)
		return (-1);

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt_types[i].fmt == fmt[*fmt_idx])
			return (fmt_types[i].func(buffer, list));
	}

	return (-1);

}

/**
 * handle_write_char - Write character to the stdout
 * @buffer: Buffer to store character
 * @c: Character to write to stdout
 *
 * Return: -1 or nonezero
 */

int handle_write_char(char *buffer, char c)
{
	buffer[0] = c;

	return (write(1, buffer, 1));
}

/**
 * first_digit - Get the first digit in a number
 * @num: Number
 *
 * Return: num
 */

int first_digit(int num)
{
	
	while (num >= 10)  
        num  /= 10;

	return (num);
}
