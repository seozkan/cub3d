/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:56:53 by seozkan           #+#    #+#             */
/*   Updated: 2023/12/10 19:34:11 by seozkan          ###   ########.fr       */
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
	// Bu kısımda, x ekseni boyunca bir adım atıldığında y ekseninde 
	// ne kadar mesafe kat edileceğini hesaplanıyor
	// ışın sola hareket ediyor
	if (params->ray_dir.x < 0)
	{
		params->step_x = -1;
		params->side_dist.x
			= (params->pos.x - params->map_x) * params->delta_dist.x;
	}
	// ışın sağa haraket ediyor 
	else
	{
		params->step_x = 1;
		params->side_dist.x
			= (params->map_x + 1.0 - params->pos.x) * params->delta_dist.x;
	}
	// ışın yukarı hareket ediyor
	if (params->ray_dir.y < 0)
	{
		params->step_y = -1;
		params->side_dist.y
			= (params->pos.y - params->map_y) * params->delta_dist.y;
	}
	// ışın aşağı haraket ediyor
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
		// Eğer x eksenindeki yan mesafe y eksenindeki yan mesafeden daha küçükse:
		// x ekseninde bir adım atılır:
		if (params->side_dist.x < params->side_dist.y)
		{
			params->side_dist.x += params->delta_dist.x;
			params->map_x += params->step_x;
			// params->side değişkeni, bu adımın x ekseninde yapıldığını belirtir (0).
			params->side = 0;
		}
		else
		{
			params->side_dist.y += params->delta_dist.y;
			params->map_y += params->step_y;
			// params->side değişkeni, bu adımın y ekseninde yapıldığını belirtir (1).
			params->side = 1;
		}
		// Eğer yeni konumun y ekseninde haritanın dışında ise (negatif veya harita 
		// yüksekliğinden büyükse fonksiyon 0 döndürerek işlemi sonlandırır.
		if (params->map_y < 0 || (size_t)params->map_y >= prog->map_h)
			return (0);
		// Eğer yeni konumun x ekseninde haritanın dışında ise (negatif veya harita 
		// genişliğinden büyükse), fonksiyon 0 döndürerek işlemi sonlandırır.
		if (params->map_x < 0 || (size_t)params->map_x >= prog->map_w)
			return (0);
		// Eğer yeni konum haritada bir duvarı temsil ediyorsa (haritada '1' olarak belirtilmişse), 
		// hit değişkenini 1 yaparak ray'ın bir duvara çarptığını belirtir ve döngü sona erer.
		if (prog->map[params->map_y][params->map_x] == '1')
			hit = 1;
	}
	return (1);
}

int	ft_draw_start_end(t_render *params)
{
	int	line_height;
	
	// sideDist'in uzunluğu zaten neredeyse perpWallDist'e eşittir. 
	// Sadece deltaDist'i bir adım geriye giderek ondan bir kez çıkarmamız gerekiyor
	
	// çarpma (hit) x yönündeyse yani side == 0 ise perp_wall_dist hesaplama metodu
	if (params->side == 0)
		params->perp_wall_dist = (params->side_dist.x - params->delta_dist.x);
	// çarpma (hit) y yönündeyse yani side == 1 ise perp_wall_dist hesaplama metodu
	else
		params->perp_wall_dist = (params->side_dist.y - params->delta_dist.y);
	line_height = (int)(HEIGHT / params->perp_wall_dist);
	
	// Bu durumda, line_height negatif bir değer alırsa, bunun bir hata olduğunu ve çizim işlemine 
	// devam edilmeden önce güvenli bir değere atanması gerektiğini belirlemek amacıyla 
	// kontrol eklenmiştir.
	if (line_height < 0)
		line_height = INT_MAX;
	// Çizime başlanacak yükseklik, line_height'ın yarısının ekran yüksekliğinden çıkarılmasıyla
	// ve ekranın ortasına eklenmesiyle hesaplanır.
	// Eğer params->draw_start negatifse, params->draw_start 0 olarak atanır.
	params->draw_start = -line_height / 2 + HEIGHT / 2;
	if (params->draw_start < 0)
		params->draw_start = 0;
	params->draw_end = line_height / 2 + HEIGHT / 2;
	if (params->draw_end >= HEIGHT)
		params->draw_end = HEIGHT - 1;
	return (line_height);
}
