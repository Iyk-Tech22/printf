#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

#define BUFFER 1024

/**
 * _printf - Print to the standard out.
 * @format: String to format and print.
 * @...: Varargs
 *
 * Return: number of byte written
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int  seek = 0;
	int size = BUFFER;
	char *buffer = NULL;
	va_list arg;
	
	buffer = malloc(sizeof(char) * buffer_size);

	if (!buffer)
	{
		return (-1);
	}

	va_start(arg, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{

			if (format[i + 1] == 'c')
			{
				char c = va_arg(arg, int);
				
				w_buffer(&buffer, c , &buffer_size, &seek);
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(arg, char*);

				str_formatter(&buffer, str, &size, &seek);
			}
			else if (format[i + 1] == '%')
			{
				w_buffer(&buffer, '%' , &size, &seek);
			}

			i++;
		}
		else
		{
			write_to_buffer(&buffer, format[i], &size, &seek);
		}

		i++;
	}
	
	write(1, buffer, seek);
	free(buffer);
	return (seek);
}














		
