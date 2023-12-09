/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:37:17 by dsanchez          #+#    #+#             */
/*   Updated: 2023/12/08 16:31:17 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

int	ft_are_digits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_close(t_cub *cub)
{
	ft_free_all(cub);
	exit(0);
}

int	err(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

size_t	ft_splitlen(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
