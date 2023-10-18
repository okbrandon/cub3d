/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:27:16 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/18 18:36:50 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* TODO: Better direction finder by parsing 
 * SOUTH: dir_x = 0, dir_y = 1, plane_x = -0.66, plane_y = 0;
 * NORTH: dir_x = 0, dir_y = -1, plane_x = 0.66, plane_y = 0;
 * EAST: dir_x = 1, dir_y = 0, plane_x = 0, plane_y = 0.66;
 * WEST: dir_x = -1, dir_y = 0, plane_x = 0, plane_y = -0.66;
 */
static t_player	ft_init_player(t_map map)
{
	t_player	player;
	int			i;
	int			j;

	i = 0;
	while (i < map.height -1)
	{
		j = 0;
		while (j < map.width- 1)
		{
			if (map.matrix[i][j] == 'N')
			{
				player.dir_x = 0;
				player.dir_y = -1;
				player.plane_x = 0.66;
				player.plane_y = 0;
			}
			else if (map.matrix[i][j] == 'S')
			{
				player.dir_x = 0;
				player.dir_y = 1;
				player.plane_x = -0.66;
				player.plane_y = 0;
			}
			else if (map.matrix[i][j] == 'E')
			{
				player.dir_x = 1;
				player.dir_y = 0;
				player.plane_x = 0;
				player.plane_y = 0.66;
			}
			else if (map.matrix[i][j] == 'W')
			{
				player.dir_x = -1;
				player.dir_y = 0;
				player.plane_x = 0;
				player.plane_y = -0.66;
			}
			player.pos_x = j - 0.5;
			player.pos_y = i - 0.5;
			j++;
		}
		i++;
	}
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

static t_textures	ft_init_textures(void)
{
	t_textures	textures;

	textures.south = ft_to_trgb(0, 255, 0, 0); // red
	textures.north = ft_to_trgb(0, 0, 255, 0); // green
	textures.east = ft_to_trgb(0, 0, 0, 255); // blue
	textures.west = ft_to_trgb(0, 255, 255, 255); // white
	return (textures);
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
	ray.side_dist_x = 0;
	ray.side_dist_y = 0;
	ray.delta_dist_x = 0;
	ray.delta_dist_y = 0;
	ray.perp_wall_dist = 0;
	ray.step_x = 0;
	ray.step_y = 0;
	ray.side_hit = 0;
	ray.wall_hit = 0;
	return (ray);
}

t_cub	*ft_init_cub(char *filepath)
{
	t_cub	*cub;

	cub = ft_calloc(1, sizeof(t_cub));
	if (!cub)
		ft_error("struct cub3d malloc failed");
	cub->mlx = ft_init_mlx(filepath);
	cub->textures = ft_init_textures();
	cub->map = ft_unsafe_parse(cub, filepath);
	cub->player = ft_init_player(cub->map);
	cub->raycast = ft_init_raycast();
	cub->filepath = filepath;
	return (cub);
}
