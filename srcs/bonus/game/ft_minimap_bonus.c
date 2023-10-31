/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:55:33 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/31 10:06:40 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	ft_draw_square(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_MULT)
	{
		j = 0;
		while (j < MINIMAP_MULT)
		{
			ft_mlx_pixel_put(cub, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_minimap(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (j < ft_strlen(cub->map.matrix[i]))
		{
			if (cub->map.matrix[i][j] == '1')
				ft_draw_square(cub, j * MINIMAP_MULT + 10, i * MINIMAP_MULT \
					+ 10, 0x000000);
			j++;
		}
		i++;
	}
	ft_draw_square(cub, (int) cub->player.pos_y * MINIMAP_MULT + 10,
		(int) cub->player.pos_x * MINIMAP_MULT + 10, 0xFF0000);
}
