/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:14:35 by lnicolos          #+#    #+#             */
/*   Updated: 2024/04/12 17:27:20 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_str(char *str);
int	print_format(char letter, va_list ap);
int	print_digit(long n, int base);
int	print_hexa(long n, char letter);
int	print_ptr(unsigned long n);

#endif
