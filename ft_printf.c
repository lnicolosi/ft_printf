/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:20:50 by lnicolos          #+#    #+#             */
/*   Updated: 2024/04/12 17:25:43 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char letter, va_list ap)
{
	int	count;

	count = 0;
	if (letter == 'c')
		count += print_char(va_arg(ap, int));
	else if (letter == 's')
		count += print_str(va_arg(ap, char *));
	else if (letter == 'p')
	{
		count += write(1, "0x", 2);
		count += print_ptr(va_arg(ap, unsigned long));
	}
	else if (letter == 'd' || letter == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (letter == 'u')
		count += print_digit((long)(va_arg(ap, unsigned int)), 10);
	else if (letter == 'x' || letter == 'X')
		count += print_hexa((long)(va_arg(ap, unsigned int)), letter);
	else if (letter == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
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
