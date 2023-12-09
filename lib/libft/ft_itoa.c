/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:06:06 by seozkan           #+#    #+#             */
/*   Updated: 2022/12/15 16:12:33 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(long nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		size++;
	}
	else if (nbr == 0)
	{
		size = 1;
	}
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;

	nbr = n;
	size = ft_size(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	*(str + size--) = '\0';
	if (nbr == 0)
		*(str) = '0';
	if (nbr < 0)
	{
		nbr = -nbr;
		*(str) = '-';
	}
	while (nbr > 0)
	{
		*(str + size--) = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
