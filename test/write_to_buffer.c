#include <stdlib.h>

/**
 * write_to_buffer - Write character to a buffer.
 * @buffer: Buffer address
 * @c: Character to write to buffer.
 * @buffer_size: Size of the buffer.
 * @seek: Seek for the buffer
 *
 * Return: void
 */

void write_to_buffer(char **buffer, char c, int *buffer_size, int *seek)
{
	if (!buffer)
	{
		exit(1);
	}

	if (*seek < *buffer_size)
	{
		int idx = *seek;

		buffer[0][idx] = c;
		(*seek)++;
	}
	else
	{
		int i = 0;
		int new_buffer_size = (*buffer_size) *= 2;
		char *new_buffer;

		new_buffer = malloc(sizeof(char) * new_buffer_size);

		if (!new_buffer)
		{
			exit(1);
		}

		for (i = 0; i < *seek; i++)
		{
			new_buffer[i] = (*buffer)[i];
		}
		new_buffer[(*seek)++] = c;
		*buffer = new_buffer;
	}
}
