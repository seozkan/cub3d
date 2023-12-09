/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:42:35 by seozkan           #+#    #+#             */
/*   Updated: 2023/12/07 16:31:00 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		len += ft_putchar(*str++);
	return (len);
}

int	ft_nbr(unsigned long long nbr, int base, char *str, int mod)
{
	int	nbr_list[100];
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (mod == 1 && (int)nbr < 0)
	{
		nbr *= -1;
		len += ft_putchar('-');
	}
	if (mod == 2)
	{
		len += ft_putstr("0x");
	}
	if (nbr == 0)
		len += ft_putchar('0');
	while (nbr)
	{
		nbr_list[i++] = nbr % base;
		nbr = nbr / base;
	}
	while (i--)
		len += ft_putchar(str[nbr_list[i]]);
	return (len);
}

int	ft_format(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'u')
		len += ft_nbr(va_arg(args, unsigned int), 10, "0123456789", 0);
	else if (format == 'd' || format == 'i' || format == 'u')
		len += ft_nbr(va_arg(args, int), 10, "0123456789", 1);
	else if (format == 'p')
		len += ft_nbr(va_arg(args, unsigned long long), 16, "0123456789abcdef",
				2);
	else if (format == 'x')
		len += ft_nbr(va_arg(args, unsigned int), 16, "0123456789abcdef", 0);
	else if (format == 'X')
		len += ft_nbr(va_arg(args, unsigned int), 16, "0123456789ABCDEF", 0);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_format(args, *str);
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}
