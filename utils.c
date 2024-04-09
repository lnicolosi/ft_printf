#include "ft_printf.h"

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
