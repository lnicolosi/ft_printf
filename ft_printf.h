#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char* format, ...);
int	print_char(char c);
int print_str(char *str);
int	print_format(char letter, va_list ap);

#endif
