/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:37:43 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/18 11:32:27 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_draw_vert_line(t_cub *cub, int x, t_vector vector, int color)
{
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < (int)vector.x)
			ft_mlx_pixel_put(cub, x, y, cub->textures.ceiling);
		else if (y >= (int)vector.x && y <= (int)vector.y)
			ft_mlx_pixel_put(cub, x, y, color);
		else
			ft_mlx_pixel_put(cub, x, y, cub->textures.floor);
	}
}

void	ft_draw_textures(t_cub *cub, int x)
{
	t_vector	vector;

	vector.x = cub->raycast.draw_from;
	vector.y = cub->raycast.draw_to;
	if (!cub->raycast.side_hit)
	{
		if (cub->raycast.ray_dir_x < 0)
			ft_draw_vert_line(cub, x, vector, cub->textures.west);
		else
			ft_draw_vert_line(cub, x, vector, cub->textures.east);
	}
	else
	{
		if (cub->raycast.ray_dir_y > 0)
			ft_draw_vert_line(cub, x, vector, cub->textures.south);
		else
			ft_draw_vert_line(cub, x, vector, cub->textures.north);
	}
}
