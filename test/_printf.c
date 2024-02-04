#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFFER 1024

/**
 * _printf - Print text to the stdout.
 * @format: Text to print to stdout.
 * @...: Varags
 *
 * Return: void
 */

void _printf(const char *format, ...)
{
    int i = 0;
    int buffer_seek = 0;
    char *buffer;
    char *error;
    va_list args;
    
    va_start(args, format);
    buffer = malloc(sizeof(char) * BUFFER);
    
    if(!buffer)
    {  
        error = "Malloc Failed\n";
        write(2, error, strlen(error)); 
        exit(1);
    }

    while(format[i] != '\0')
    {
        if(format[i] == '%')
        { 
            if(format[i+1] == 'c')
            {
                char arg = va_arg(args, int);
                buffer[buffer_seek] = arg;
                buffer_seek++;
            }
            else if(format[i+1] == 'd')
            {
                int arg = va_arg(args, int);
                buffer[buffer_seek++] = arg;
            }
            i++;           
        }
        else
        {
            buffer[buffer_seek] = format[i];
            buffer_seek++;
        }
        i++;
    }

    va_end(args);

    // WRITE TO THE STDOUT
    write(1, buffer, buffer_seek);
    free(buffer);
}
