/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:20:50 by lnicolos          #+#    #+#             */
/*   Updated: 2024/04/03 19:43:38 by lnicolos         ###   ########.fr       */
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



int	print_format(char letter, va_list ap)
{
	int count;
	
	count = 0;
	if (letter == 'c')
		count = print_char(va_arg(ap, int));
	else if (letter == 's')
		count = print_str(va_arg(ap, char *));
	else if (letter == 'p') //same like %x + '0x'

	else if (letter == 'd' || letter == 'i')

	else if (letter == 'u')

	else if (letter == 'x' || letter == 'X')
	
	else if (letter == '%')

	return (count);
}

int	ft_printf(const char *format, ...)
{
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

	count = ft_printf("le char : %c - %c\n", 'X', 'X');
	printf("longueure ft_printf %d\n\n", count);

	count = printf("le char : %c - %c\n", 'Z', 'Z');
	printf("longueure printf %d\n", count);


	return 0;
}
