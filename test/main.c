#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFFER 4

/**
 * main - Program entry
 * 
 * Return: on success 0, on error 1
 */

int main(void)
{
	int buffer_size = BUFFER;
	int seek = 0;
	char  *buffer = malloc(sizeof(char) * BUFFER);
	
	for (; seek < 4; seek++)
	{
		buffer[seek] = 'a' + seek;
	}
	
	printf("Seek: %d Buffer:%d\n", seek, buffer_size);
	write_to_buffer(&buffer, ' ', &buffer_size, &seek);
	write_to_buffer(&buffer, 'g', &buffer_size, &seek);
	write_to_buffer(&buffer, 'u', &buffer_size, &seek);
	write_to_buffer(&buffer, 'y', &buffer_size, &seek);
	write_to_buffer(&buffer, 's', &buffer_size, &seek);
	write_to_buffer(&buffer, '\n', &buffer_size, &seek);
	write(1, buffer, seek);
	printf("Seek: %d Buffer:%d\n", seek, buffer_size);
	return (0);
} 
