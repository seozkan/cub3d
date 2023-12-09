/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:02:13 by mclerico          #+#    #+#             */
/*   Updated: 2023/12/08 16:30:56 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_hooks_press(int keycode, t_cub *vars)
{
	if (keycode == KEY_ESC)
		ft_close(vars);
	if (keycode == KEY_RIGHT)
		vars->keys.right = 1;
	else if (keycode == KEY_LEFT)
		vars->keys.left = 1;
	else if (keycode == KEY_W)
		vars->keys.w = 1;
	else if (keycode == KEY_S)
		vars->keys.s = 1;
	else if (keycode == KEY_A)
		vars->keys.a = 1;
	else if (keycode == KEY_D)
		vars->keys.d = 1;
	return (0);
}

int	ft_hooks_release(int keycode, t_cub *vars)
{
	if (keycode == KEY_RIGHT)
		vars->keys.right = 0;
	else if (keycode == KEY_LEFT)
		vars->keys.left = 0;
	else if (keycode == KEY_W)
		vars->keys.w = 0;
	else if (keycode == KEY_S)
		vars->keys.s = 0;
	else if (keycode == KEY_A)
		vars->keys.a = 0;
	else if (keycode == KEY_D)
		vars->keys.d = 0;
	return (0);
}
