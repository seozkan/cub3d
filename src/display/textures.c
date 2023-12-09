/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:10 by seozkan           #+#    #+#             */
/*   Updated: 2023/12/08 16:33:00 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	load_textures(t_cub *prog, t_text *texture, char *path)
{
	if (!path || ft_strlen(path) == 0)
		return (0);
	texture->img.img = mlx_xpm_file_to_image(prog->mlx,
			path, &texture->w, &texture->h);
	if (texture->img.img == NULL)
		return (0);
	texture->img.addr = mlx_get_data_addr(texture->img.img,
			&texture->img.bits_per_pixel, &texture->img.line_length,
			&texture->img.endian);
	if (texture->img.addr == NULL)
		return (0);
	return (1);
}

void	init_textures(t_cub *prog)
{
	if (!load_textures(prog, &prog->tex[0], prog->no_path)
		|| !load_textures(prog, &prog->tex[1], prog->so_path)
		|| !load_textures(prog, &prog->tex[2], prog->we_path)
		|| !load_textures(prog, &prog->tex[3], prog->ea_path))
	{
		return ;
	}
}
