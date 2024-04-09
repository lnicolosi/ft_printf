/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:20:50 by lnicolos          #+#    #+#             */
/*   Updated: 2024/04/09 14:37:35 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	print_char(char c)
{
	return write(1, &c, 1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		print_char(str[i]);
		i++;
	}
	return (i);
}

int	print_digit(long n, int base)
{
	int		count;
	char*	symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return print_digit(-n, base) + 1;
	}
	else if (n < base)
		return print_char(symbols[n]);
	else
	{
		count = print_digit(n / base, base);
		return count + print_digit(n % base, base);
	}
}

int	print_hexa(long n, char letter)
{
	int		count;
	char*	minus;
	char*	majus;

	minus = "0123456789abcdef";
	majus = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return print_hexa(-n, letter) +1;
	}
	else if (n < 16)
	{
		if (letter == 'x')
			return print_char(minus[n]);
		else
			return print_char(majus[n]);
	}
	else
	{
		count = print_hexa(n / 16, letter);
		return count + print_hexa(n % 16, letter);
	}	
}

int	print_format(char letter, va_list ap)
{
	int count;
	
	count = 0;
	if (letter == 'c')
		count += print_char(va_arg(ap, int));
	else if (letter == 's')
		count += print_str(va_arg(ap, char *));
	else if (letter == 'p') //same like %x + '0x'
	{
		count += write(1, "0x", 2);
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);
	}
	else if (letter == 'd' || letter == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10);
	//else if (letter == 'u')

	else if (letter == 'x' || letter == 'X')
		count += print_hexa((long)(va_arg(ap, unsigned int)), letter);
	else if (letter == '%')
		count += print_char('%');
	else
		
	return (count);
}

int	ft_printf(const char *format, ...)
{
	/*
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	*/
	int	i;
	int	count;
	va_list ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	while(format[i] != '\0')
	{
		if(format[i] == '%')
		{
			i++;
			count += print_format(format[i++], ap);
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}

	}	
	va_end(ap);
	return (count);
}


int main(void)
{
	int count = 0;

	count = ft_printf("exa et decimal : %x %x \n", -1, 42);
	printf("longueure ft_printf %d\n\n", count);

	count = printf("exa et decimal : %x %x \n", -1, 42);
	printf("longueure printf %d\n", count);


	return 0;
}
