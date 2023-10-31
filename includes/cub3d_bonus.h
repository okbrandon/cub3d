/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:02:20 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/31 20:15:46 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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

# define WIN_WIDTH		1280
# define WIN_HEIGHT		800

# define TEX_WIDTH		64
# define TEX_HEIGHT		64
# define SPRITE_WIDTH	24
# define SPRITE_HEIGHT	24

# define U_DIV			1.0
# define V_DIV			1.0
# define V_MOVE			0.0

# define DIR_NORTH		0
# define DIR_SOUTH		1
# define DIR_WEST		2
# define DIR_EAST		3
# define FST_SPRITE		4
# define SND_SPRITE		5
# define TRD_SPRITE		6
# define FRTH_SPRITE	7
# define FITH_SPRITE	8
# define TEXTURES_COUNT	9

# define KEY_DOOR_OPEN	31
# define KEY_DOOR_CLOSE	8
# define KEY_FORWARD	13
# define KEY_BACKWARD	1
# define KEY_LEFT		0
# define KEY_RIGHT		2
# define KEY_ROT_LEFT	123
# define KEY_ROT_RIGHT	124
# define KEY_ESCAPE		53

# define MOVE_SPEED		0.125
# define ROT_SPEED		0.075

# define MINIMAP_MULT	8

typedef struct s_vector
{
	double			x;
	double			y;
}				t_vector;

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

typedef struct s_sprite
{
	t_vector	pos;
	double		dist;
}				t_sprite;

typedef struct s_map
{
	int				sprites_count;
	int				width;
	int				height;
	int				player_x;
	int				player_y;
	char			player_dir;
	char			**matrix;
	t_sprite		*sprites;
}				t_map;

typedef struct s_textures
{
	t_mlx	*mlx_textures;
	int		current_sprite;
	int		floor;
	int		ceiling;
}			t_textures;

typedef struct s_raycast
{
	bool	wall_hit;
	bool	side_hit;
	bool	door_hit;
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
	int		*z_buffer;
}			t_raycast;

typedef struct s_spritecast
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		sprite_height;
	int		sprite_width;
	int		draw_start_x;
	int		draw_start_y;
	int		draw_end_x;
	int		draw_end_y;
	int		tex_x;
	int		tex_y;
	int		v_move_screen;
}				t_spritecast;

typedef struct s_cub
{
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_textures		textures;
	t_raycast		raycast;
	t_spritecast	spritecast;
	char			*filepath;
}				t_cub;

/* ft_initializer.c */
t_cub			*ft_init_cub(char *filepath);

/* ft_raycaster.c */
void			ft_raycast(t_cub *cub);

/* ft_drawer.c */
void			ft_draw_textures(t_cub *cub, int x);

/* ft_args_checker.c */
char			*ft_get_file_extension(char *filename);
void			ft_check_args(int argc, char **argv);

/* ft_key_handler.c */
bool			ft_is_wall(float x, float y, t_cub *cub);
int				ft_key_press_handler(int keycode, t_cub *cub);

/* ft_mlx_utils.c */
int				ft_img_renderer(t_cub *cub);
int				ft_get_pixel_color(t_mlx *mlx, int x, int y);
void			ft_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int				ft_to_trgb(int t, int r, int g, int b);

/* ft_other_utils.c */
double			ft_abs(double x);
void			ft_error(char *message);
bool			ft_is_valid_rgb(int r, int g, int b);
char			**ft_strsjoin(char **strs, char *str);
int				dir_from_id(char *identifier);

/* ft_parser.c */
t_map			ft_map_parser(char *path);

/* ft_tx_parser.c */
t_textures		ft_texture_parser(t_cub *cub, char *path);

/* ft_parser_utils.c */
bool			ft_is_map_valid(t_map map);
bool			ft_is_line_valid(char *line);
void			ft_find_player(t_map *map);

/* ft_scan.c */
int				*scan_rgb(char *identifier, char *line);
int				ft_strslen(char **strs);

/* ft_floodfill_utils.c */
void			fl_find_player(t_map map, int *sr, int *sc);
bool			fl_visited_boundary(bool **visited, t_map map);
void			fl_free(bool **visited, t_map map);

/* ft_floodfill.c */
bool			fl_can_exit(t_map map);

/* ft_free_utils.c */
int				ft_close(t_cub *cub);

/* ft_door_utils.c */
void			ft_interact_with_door(t_cub *cub, int keycode);

/* ft_sprite_utils.c */
void			ft_sort_sprites_by_dist(t_cub *cub);
void			ft_apply_sprite_texture(t_cub *cub, int direction, int x, int y);
void			ft_find_sprites(t_map *map);

/* ft_minimap.c */
void			ft_draw_minimap(t_cub *cub);

/* ft_spritecaster.c */
void			ft_spritecast(t_cub *cub);

/* ft_sprite_init.c */
t_spritecast	ft_init_spritecast(void);
void			ft_init_sprites_textures(t_cub *cub, t_textures *textures);
int				ft_run_sprite_cycle(t_cub *cub);

#endif