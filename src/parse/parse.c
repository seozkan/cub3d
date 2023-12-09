/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:58:12 by seozkan           #+#    #+#             */
/*   Updated: 2023/12/08 16:53:14 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_check_valid_map_line(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		// map'in satırında 10 boşluk NSEW karakterleri dışında bir karakter varsa
		// hata mesajı yazdırılır
		if (!ft_strchr("10 NSEW", line[i]))
		{
			ft_printf("Error: %c is not a valid char\n", line[i]);
			return (0);
		}
		// map'in satırında NSEW karakterlerinden biri satırdaysa ve start pozisyonu
		// 0 a eşit değilse hata mesajı yazdırır
		// start way hemen aşağıdaki else if de değer atanmışsa burada hata verecektir
		// yani haritada iki başlangıç pozisyonu olması durumunda
		else if (ft_strchr("NSEW", line[i]) && cub->starting_way != 0)
		{
			ft_printf("Error: Only one starting point valid.\n");
			return (0);
		}
		else if (ft_strchr("NSEW", line[i]) && cub->starting_way == 0)
		{
			cub->starting_way = line[i];
			cub->pos.x = (double)i;
			cub->pos.y = (double)cub->map_h;
		}
		i++;
	}
	return (1);
}

int	ft_parse_map(t_cub *cub, char *line)
{
	int		i;
	size_t	w;
	char	**new_map;

	i = -1;
	if (!ft_check_valid_map_line(cub, line))
		return (0);
	// map satır uzunluğu bulunuyor
	w = ft_strlen(line);
	// map satır sayısı 1 arttırılıyor
	cub->map_h++;
	// map satır uzunluğundan daha uzun bir satır bulunursa yeni satır uzunluğu ayarlanıyor
	if (w > cub->map_w)
		cub->map_w = w;
	new_map = ft_calloc(cub->map_h + 1, sizeof(char *));
	// cub ün içindeki map verisinden önceki satır değerleri okunuyor new_map'e yazılıyor
	while (cub->map[++i])
		new_map[i] = cub->map[i];
	// son satır new_map'a ekleniyor
	new_map[i] = line;
	new_map[i + 1] = NULL;
	// cub içindeki map temizleniyor
	free(cub->map);
	// yeni map cub map a atanıyor
	cub->map = new_map;
	return (1);
}

int	ft_check_path_and_color(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->no_path == NULL || cub->so_path == NULL || cub->we_path == NULL
		|| cub->ea_path == NULL)
	{
		printf("Error in paths\n");
		return (0);
	}
	while (i < 3)
	{
		if (cub->f_color[i] == 256 || cub->c_color[i] == 256)
		{
			printf("Error in colors\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_parse_line(char *line, t_cub *cub, int *num)
{
	int	ret;

	// bu koşul boş satırların kontrol edilip bellekten silinmesi için
	if ((int)ft_strlen(line) <= 1)
	{
		ret = *num != -1;
		if (ret != 0)
			free(line);
	}
	// bu satır yönlendirme ve renk kodlarının okunması için
	else if (*num < 6 && *num != -1)
		ret = is_valid_param(cub, line, num);
	// bu satır haritanın 1 ve 0 larının okunması için
	else
	{
		*num = -1;
		if (!ft_check_path_and_color(cub))
			return (0);
		ret = ft_parse_map(cub, line);
	}
	if (ret == 0)
		ft_printf("Error\n");
	return (ret);
}

int	ft_parse_file(char *filename, t_cub *cub)
{
	int		fd;
	int		num;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	num = 0;
	while (line)
	{
		if (!ft_parse_line(line, cub, &num))
		{
			free(line);
			return (0);
		}
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	if (!cub->starting_way)
		return (err("No starting way\n"));
	// bu fonksiyon tüm satır uzunluklarını aynı yapmak için eksik satır uzunluklarının
	// sonunu ' ' karakter ile doldurur
	ft_resize_map(cub);
	ft_check_closed(cub);
	return (1);
}
