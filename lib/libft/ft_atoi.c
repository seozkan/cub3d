/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:36:17 by seozkan           #+#    #+#             */
/*   Updated: 2022/12/15 16:11:03 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}

int	ft_sign(int c)
{
	if (c == '+' || c == '-')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	c;
	int	mark;
	int	res;

	c = 0;
	mark = 1;
	res = 0;
	while (ft_isspace(str[c]) == 1)
		c++;
	if (ft_sign(str[c]) == 1)
	{
		if (str[c] == '-')
			mark *= -1;
		c++;
	}
	while (ft_isdigit(str[c]) == 1)
	{
		res = (res * 10) + (str[c] - '0');
		c++;
	}
	return (res * mark);
}
