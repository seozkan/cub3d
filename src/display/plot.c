/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:56:37 by seozkan           #+#    #+#             */
/*   Updated: 2023/12/07 16:56:49 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || y < 0 || x < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_data *data, int x, int y)
{
	char	*dst;
	int		color;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

int	ft_bigger(double x, double y)
{
	if (x < y)
		return (1);
	return (-1);
}

int	get_fromrgb(int rgb[3])
{
	if (!rgb)
		return (0);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	vertical_line(double x, double yi, double yo, t_cub params)
{
	int	s;
	int	color;

	s = ft_bigger(yi, yo);
	if (yi == 0)
		color = get_fromrgb(params.c_color);
	else
		color = get_fromrgb(params.f_color);
	while (yi != yo)
	{
		my_mlx_pixel_put(&(params.img), x, yi, color);
		yi += s;
	}
}
