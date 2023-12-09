/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:56:53 by seozkan           #+#    #+#             */
/*   Updated: 2023/12/07 16:56:55 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

double	ft_abs(double num)
{
	if (num > 0)
		return (num);
	return (num * -1);
}

void	ft_side_dist(t_render *params)
{
	if (params->ray_dir.x < 0)
	{
		params->step_x = -1;
		params->side_dist.x
			= (params->pos.x - params->map_x) * params->delta_dist.x;
	}
	else
	{
		params->step_x = 1;
		params->side_dist.x
			= (params->map_x + 1.0 - params->pos.x) * params->delta_dist.x;
	}
	if (params->ray_dir.y < 0)
	{
		params->step_y = -1;
		params->side_dist.y
			= (params->pos.y - params->map_y) * params->delta_dist.y;
	}
	else
	{
		params->step_y = 1;
		params->side_dist.y
			= (params->map_y + 1.0 - params->pos.y) * params->delta_dist.y;
	}
}

int	ft_dda(t_cub *prog, t_render *params)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (params->side_dist.x < params->side_dist.y)
		{
			params->side_dist.x += params->delta_dist.x;
			params->map_x += params->step_x;
			params->side = 0;
		}
		else
		{
			params->side_dist.y += params->delta_dist.y;
			params->map_y += params->step_y;
			params->side = 1;
		}
		if (params->map_y < 0 || (size_t)params->map_y >= prog->map_h)
			return (0);
		if (params->map_x < 0 || (size_t)params->map_x >= prog->map_w)
			return (0);
		if (prog->map[params->map_y][params->map_x] == '1')
			hit = 1;
	}
	return (1);
}

int	ft_draw_start_end(t_render *params)
{
	int	line_height;

	if (params->side == 0)
		params->perp_wall_dist = (params->side_dist.x - params->delta_dist.x);
	else
		params->perp_wall_dist = (params->side_dist.y - params->delta_dist.y);
	line_height = (int)(HEIGHT / params->perp_wall_dist);
	if (line_height < 0)
		line_height = INT_MAX;
	params->draw_start = -line_height / 2 + HEIGHT / 2;
	if (params->draw_start < 0)
		params->draw_start = 0;
	params->draw_end = line_height / 2 + HEIGHT / 2;
	if (params->draw_end >= HEIGHT)
		params->draw_end = HEIGHT - 1;
	return (line_height);
}
