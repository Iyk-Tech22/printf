#include "main.h"

void print_chars(char *buffer, int *buffer_idx);

/**
 * _printf - Print to stdout
 * @format: String to format and print
 *
 * Return: nonezore or -1
 */

int _printf(char *format, ...)
{
	int i, printed, printed_chars = 0, buffer_idx = 0;
	char *buffer;
	va_list list;

	buffer = malloc(BUFFER);

	if (!buffer || !format)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_idx++] = format[i];

			if (buffer_idx == BUFFER)
				print_chars(buffer, &buffer_idx);

			printed_chars++;
		}

		else
		{
			print_chars(buffer, &buffer_idx);
			i++;
			printed = handle_print(format, &i, list, buffer);

			if (printed < 0)
			{
				free(buffer);
				return (-1);
			}

			printed_chars += printed;
		}
	}

	va_end(list);
	print_chars(buffer, &buffer_idx);
	free(buffer);

	return (printed_chars);
}

/**
 * print_chars - Print to the stdout
 * @buffer: Buffer
 * @buffer_idx: Buffer index
 *
 * Return: void
 */

void print_chars(char *buffer, int *buffer_idx)
{
	write(1, buffer, *buffer_idx);
	*buffer_idx = 0;
}
