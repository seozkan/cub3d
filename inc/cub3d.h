/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:56:26 by seozkan           #+#    #+#             */
/*   Updated: 2023/12/13 22:31:31 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			right;
	int			left;
}				t_keys;

typedef struct s_text
{
	int			h;
	int			w;
	t_data		img;
}				t_text;

typedef struct s_render
{
	t_point		pos;
	t_point		dir;
	t_point		plane;
	t_point		ray_dir;
	t_point		side_dist;
	t_point		delta_dist;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			side;
	double		perp_wall_dist;
	int			draw_start;
	int			draw_end;
}				t_render;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	t_data		img;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			f_color[3];
	int			c_color[3];
	int			tex_y;
	int			tex_x;
	char		**map;
	char		starting_way;
	t_point		pos;
	t_render	*params;
	t_text		tex[4];
	size_t		map_w;
	size_t		map_h;
	int			move;
	t_keys		keys;
}				t_cub;

void			ft_set_dir(t_cub *prog);

//	utils/utils.c
int				ft_max(int x, int y);

//	utils/hooks.c
int				ft_close(t_cub *cub);
int				ft_hooks_press(int keycode, t_cub *vars);
int				ft_hooks_release(int keycode, t_cub *vars);

//	utils/frees.c
size_t			ft_splitlen(char **split);
void			ft_free_split(char **split);
void			ft_free_cub(t_cub *cub);
void			ft_free_all(t_cub *cub);

// utils/errors.c
int				err(char *msg);

// parse/utils.c
int				is_valid_param(t_cub *cub, char *line, int *num);
int				ft_check_file_extension(char *name);

// display text
void			init_textures(t_cub *prog);

// parse/parse_map.c
int				ft_check_closed(t_cub *cub);
void			ft_resize_map(t_cub *cub);

// parse/parse.c
int				ft_parse_file(char *filename, t_cub *cub);
void			plot_line(t_point p1, t_point p2, t_data img, int color);
double			ft_abs(double num);

// display/transform.c
void			ft_move_straight(t_cub *prog, t_render *params);
void			ft_move_side(t_cub *prog, t_render *params);
void			ft_rotate(t_cub *prog, t_render *params);
int				ft_texnum(t_render *params);

// display/plot.c
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				get_pixel_color(t_data *data, int x, int y);
void			draw_sky_or_floor(double x, double yi, double yo, t_cub params);

// display/render_utils.c
double			ft_abs(double num);
void			ft_side_dist(t_render *params);
int				ft_dda(t_cub *prog, t_render *params);
int				ft_draw_start_end(t_render *params);

// display/render.c
int				ft_start(t_cub *prog);

# define WALL 0xCCFFCC
# define WALL_2 0x66FF66
# define WIDTH 720
# define HEIGHT 480
# define X_OFFSET 20
# define Y_OFFSET 20
# define NO 0
# define SO 1
# define WE 2
# define EA 3

# ifdef OSX
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_P 35
#  define KEY_PLUS 69
#  define KEY_C 8
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
# elif LINUX
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_P 112
#  define KEY_PLUS 43
#  define KEY_C 99
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
# else
#  define LINUX
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_P 112
#  define KEY_PLUS 61
#  define KEY_C 99
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
# endif
#endif
