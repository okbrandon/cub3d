/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:37:43 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/31 19:08:59 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	ft_draw_floor_ceiling(t_cub *cub, int x, int from)
{
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y <= from)
			ft_mlx_pixel_put(cub, x, y, cub->textures.ceiling);
		else
			ft_mlx_pixel_put(cub, x, y, cub->textures.floor);
	}
}

static void	ft_apply_texture(t_cub *cub, int direction, int x)
{
	int	color;

	if (!cub->raycast.door_hit)
		color = ft_get_pixel_color(&cub->textures.mlx_textures[direction], \
			cub->raycast.tex_x, cub->raycast.tex_y);
	else
		color = ft_to_trgb(0, 255, 0, 0);
	ft_mlx_pixel_put(cub, x, cub->raycast.draw_from, color);
}

static void	ft_calc_tex_positions(t_cub *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	if (!ray->side_hit)
		ray->tex_wall_x = cub->player.pos_y + ray->perp_wall_dist \
			* ray->ray_dir_y;
	else
		ray->tex_wall_x = cub->player.pos_x + ray->perp_wall_dist \
			* ray->ray_dir_x;
	ray->tex_wall_x -= floor(ray->tex_wall_x);
	ray->tex_x = ray->tex_wall_x * TEX_WIDTH;
	if (!ray->side_hit && ray->ray_dir_x > 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	if (ray->side_hit && ray->ray_dir_y < 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	ray->tex_step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_from - WIN_HEIGHT / 2 \
		+ ray->line_height / 2) * ray->tex_step;
}

void	ft_draw_textures(t_cub *cub, int x)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ft_calc_tex_positions(cub);
	ft_draw_floor_ceiling(cub, x, ray->draw_from);
	while (ray->draw_from++ < ray->draw_to)
	{
		ray->tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->tex_step;
		if (!ray->side_hit && cub->player.pos_x < ray->map_x)
			ft_apply_texture(cub, DIR_SOUTH, x);
		else if (!ray->side_hit && cub->player.pos_x > ray->map_x)
			ft_apply_texture(cub, DIR_NORTH, x);
		else if (ray->side_hit && cub->player.pos_y < ray->map_y)
			ft_apply_texture(cub, DIR_EAST, x);
		else if (ray->side_hit && cub->player.pos_y > ray->map_y)
			ft_apply_texture(cub, DIR_WEST, x);
	}
}
