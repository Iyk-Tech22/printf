#include "main.h"
#include <stdio.h>

/**
 * main - Program entry
 * 
 * Return: on success 0, on error 1
 */

int main(void)
{
	/**char str[] = "Coding is fun :)";**/
	int result = _printf("hello %c %s 100%% done\n", '|', "guys");
	if (result > 0)
	{
		printf("%d byte written\n", result);
		return (result);
	}
	return (-1);
} 
