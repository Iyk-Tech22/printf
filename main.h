#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFFER 1024

/***** STRUCT TYPE *****/
typedef struct fmt {
	char fmt;
	int (*func)(char *buffer, va_list list);
} fmt_t;

/***** CORE FUNC *****/
int _printf(char *format, ...);

/***** HELPER FUNCS *****/
int handle_print(char *fmt, int *fmt_idx, va_list list, char *buffer);
int handle_write_char(char *buffer, char c);

/***** PRINT FUNCS *****/
int print_char(char *buffer, va_list list);
int print_str(char *buffer, va_list list);
int print_percent(char *buffer, va_list list);


#endif
