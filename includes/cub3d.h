/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:02:20 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/26 23:37:09 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>

# define RED 			"\033[0;31m"
# define PURPLE 		"\033[38;5;141m"
# define GREY 			"\033[38;5;240m"
# define GREEN 			"\033[38;5;46m"
# define RESET 			"\033[0m"
# define BOLD 			"\033[1m"

# define TRUE			1
# define FALSE			0

# define WIN_WIDTH		1280
# define WIN_HEIGHT		800

# define TEX_WIDTH		64
# define TEX_HEIGHT		64

# define DIR_NORTH		0
# define DIR_SOUTH		1
# define DIR_WEST		2
# define DIR_EAST		3

# define KEY_FORWARD	13
# define KEY_BACKWARD	1
# define KEY_LEFT		0
# define KEY_RIGHT		2
# define KEY_ROT_LEFT	123
# define KEY_ROT_RIGHT	124
# define KEY_ESCAPE		53

# define MOVE_SPEED		0.125
# define ROT_SPEED		0.075

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			old_dir_x;
	double			old_plane_x;
}				t_player;

typedef struct s_mlx
{
	void			*mlx;
	void			*window;
	char			*addr;
	void			*img;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}			t_mlx;

typedef struct s_map
{
	int				width;
	int				height;
	char			**matrix;
}				t_map;

typedef struct s_textures
{
	t_mlx	*mlx_textures;
	int		floor;
	int		ceiling;
}			t_textures;

typedef struct s_raycast
{
	int		wall_hit;
	int		side_hit;
	int		line_height;
	int		draw_from;
	int		draw_to;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		tex_x;
	int		tex_y;
	double	tex_step;
	double	tex_pos;
	double	tex_wall_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
}			t_raycast;

typedef struct s_cub
{
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_textures		textures;
	t_raycast		raycast;
	char			*filepath;
}				t_cub;

/* ft_initializer.c */
t_cub	*ft_init_cub(char *filepath);

/* ft_raycaster.c */
void	ft_raycast(t_cub *cub);

/* ft_drawerc.c */
void	ft_draw_textures(t_cub *cub, int x);

/* ft_args_checker.c */
void	ft_check_args(int argc, char **argv);

/* ft_key_handler.c */
int		ft_key_press_handler(int keycode, t_cub *cub);

/* ft_mlx_utils.c */
int		ft_img_renderer(t_cub *cub);
int		ft_get_pixel_color(t_mlx *mlx, int x, int y);
void	ft_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int		ft_to_trgb(int t, int r, int g, int b);

/* ft_other_utils.c */
double	ft_abs(double x);
void	ft_error(char *message);
int		ft_close(t_cub *cub);

/* ft_parser.c */
t_map	ft_map_parser(char *path);

/* ft_tx_parser.c */
t_textures	ft_texture_parser(t_cub *cub, char *path);

/* ft_parser_utils.c */
int		ft_is_map_valid(t_map map);
int		ft_is_line_valid(char *line);
void	ft_normalise_width(t_map map);

/* ft_scan.c */
int		*scan_rgb(char *identifier, char *line);
int		ft_strslen(char **strs);

/* ft_debug.c */
void	print_map_matrix(t_map map);

/* ft_utils.c */
int		ft_is_valid_rgb(int r, int g, int b);
char	*ft_strcpy(char *dest, char *src);
int		dir_from_id(char *identifier);

/* ft_floodfill.c */
bool	fl_can_exit(t_map map);

#endif