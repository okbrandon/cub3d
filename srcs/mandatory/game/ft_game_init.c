/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:27:16 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/31 10:07:42 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_assign_player_dir(t_player *player, int direction)
{
	if (direction == DIR_NORTH)
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_y = 0.66;
	}
	else if (direction == DIR_SOUTH)
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_y = -0.66;
	}
	else if (direction == DIR_EAST)
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = 0.66;
	}
	else if (direction == DIR_WEST)
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = -0.66;
	}
}

static t_player	ft_init_player(t_map map)
{
	t_player	player;

	player.plane_x = 0;
	player.plane_y = 0;
	if (map.player_dir == 'N')
		ft_assign_player_dir(&player, DIR_NORTH);
	else if (map.player_dir == 'S')
		ft_assign_player_dir(&player, DIR_SOUTH);
	else if (map.player_dir == 'E')
		ft_assign_player_dir(&player, DIR_EAST);
	else if (map.player_dir == 'W')
		ft_assign_player_dir(&player, DIR_WEST);
	player.pos_x = map.player_x + 0.5;
	player.pos_y = map.player_y + 0.5;
	player.old_dir_x = 0;
	player.old_plane_x = 0;
	return (player);
}

static t_mlx	ft_init_mlx(char *filepath)
{
	t_mlx	mlx;
	char	*title;

	title = ft_strjoin("bsoubaig & evmorvan's cub3D - ", filepath);
	if (!title)
		ft_error("title malloc failed");
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		ft_error("mlx_init failed");
	mlx.window = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, title);
	if (!mlx.window)
		ft_error("mlx_new_window failed");
	mlx.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx.img)
		ft_error("mlx_new_image failed");
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, \
		&mlx.line_length, &mlx.endian);
	if (!mlx.addr)
		ft_error("mlx_get_data_addr failed");
	free(title);
	return (mlx);
}

static t_raycast	ft_init_raycast(void)
{
	t_raycast	ray;

	ray.ray_dir_x = 0;
	ray.ray_dir_y = 0;
	ray.line_height = 0;
	ray.draw_from = 0;
	ray.draw_to = 0;
	ray.map_x = 0;
	ray.map_y = 0;
	ray.tex_x = 0;
	ray.tex_y = 0;
	ray.tex_step = 0;
	ray.tex_pos = 0;
	ray.tex_wall_x = 0;
	ray.side_dist_x = 0;
	ray.side_dist_y = 0;
	ray.delta_dist_x = 0;
	ray.delta_dist_y = 0;
	ray.perp_wall_dist = 0;
	ray.step_x = 0;
	ray.step_y = 0;
	ray.side_hit = false;
	ray.wall_hit = false;
	return (ray);
}

t_cub	*ft_init_cub(char *filepath)
{
	t_cub	*cub;

	cub = ft_calloc(1, sizeof(t_cub));
	if (!cub)
		ft_error("struct cub3d malloc failed");
	cub->mlx = ft_init_mlx(filepath);
	cub->textures = ft_texture_parser(cub, filepath);
	cub->map = ft_map_parser(filepath);
	cub->player = ft_init_player(cub->map);
	cub->raycast = ft_init_raycast();
	cub->filepath = filepath;
	return (cub);
}
