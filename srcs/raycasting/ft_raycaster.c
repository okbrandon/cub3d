/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:22:53 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/28 11:20:58 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_init_ray_directions(t_cub *cub, int x)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ray->ray_dir_x = cub->player.dir_x + cub->player.plane_x * \
		(2 * x / (double)WIN_WIDTH - 1);
	ray->ray_dir_y = cub->player.dir_y + cub->player.plane_y * \
		(2 * x / (double)WIN_WIDTH - 1);
	ray->map_x = (int) cub->player.pos_x;
	ray->map_y = (int) cub->player.pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = ft_abs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = ft_abs(1 / ray->ray_dir_y);
}

static void	ft_init_dda_algorithm(t_cub *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub->player.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cub->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub->player.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cub->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	ft_apply_dda_algorithm(t_cub *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ray->wall_hit = 0;
	while (!ray->wall_hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side_hit = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side_hit = 1;
		}
		if (cub->map.matrix[ray->map_x][ray->map_y] == '1')
			ray->wall_hit = 1;
	}
	if (ray->side_hit == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

static void	ft_calc_line_height(t_cub *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_from = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_from < 0)
		ray->draw_from = 0;
	ray->draw_to = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_to >= WIN_HEIGHT)
		ray->draw_to = WIN_HEIGHT - 1;
}

void	ft_raycast(t_cub *cub)
{
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		ft_init_ray_directions(cub, x);
		ft_init_dda_algorithm(cub);
		ft_apply_dda_algorithm(cub);
		ft_calc_line_height(cub);
		ft_draw_textures(cub, x);
	}
}
