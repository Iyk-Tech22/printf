#include "main.h"

/**
 * str_formatter - Process string and copy the string content to the buffer
 * @buffer: Buffer to copy the string content
 * @str: String to copy it content
 * @buffer_size: Size of the buffer.
 * @seek: Where to start writing in the buffer.
 *
 * Return: void
 */

void str_formatter(char **buffer, char *str, int *buffer_size, int *seek)
{
	int i;
	
	
	for (i = 0; str[i] != '\0'; i++)
	{
		write_to_buffer(buffer, str[i], buffer_size, seek);
	}
}
