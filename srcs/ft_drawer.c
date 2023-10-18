/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:37:43 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/18 11:16:42 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_draw_vertical_line(t_cub *cub, int x, int from, int to, int color)
{
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < from)
			ft_mlx_pixel_put(cub, x, y, ft_to_trgb(0, 0, 0, 0));
		else if (y >= from && y <= to)
			ft_mlx_pixel_put(cub, x, y, color);
		else
			ft_mlx_pixel_put(cub, x, y, ft_to_trgb(0, 0, 0, 0));
	}
}

static void	ft_draw_floor_and_ceiling(t_cub *cub, int x)
{
	float	ds;
	int		y;

	ds = ((float)WIN_HEIGHT / 2) - ((float)cub->raycast.line_height / 2);
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < ds)
			ft_mlx_pixel_put(cub, x, y, cub->textures.ceiling);
		else if (y >= ds + cub->raycast.line_height)
			ft_mlx_pixel_put(cub, x, y, cub->textures.floor);
	}
}

void	ft_draw_textures(t_cub *cub, int x)
{
	if (!cub->raycast.side_hit)
	{
		if (cub->raycast.ray_dir_x < 0)
			ft_draw_vertical_line(cub, x, cub->raycast.draw_from, \
				cub->raycast.draw_to, cub->textures.west);
		else
			ft_draw_vertical_line(cub, x, cub->raycast.draw_from, \
				cub->raycast.draw_to, cub->textures.east);
	}
	else
	{
		if (cub->raycast.ray_dir_y > 0)
			ft_draw_vertical_line(cub, x, cub->raycast.draw_from, \
				cub->raycast.draw_to, cub->textures.south);
		else
			ft_draw_vertical_line(cub, x, cub->raycast.draw_from, \
				cub->raycast.draw_to, cub->textures.north);
	}
	ft_draw_floor_and_ceiling(cub, x);
}
